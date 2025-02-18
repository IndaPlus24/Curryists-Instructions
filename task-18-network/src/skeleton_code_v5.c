/*
 * Skeleton code generated using Google Gemini 2.0 Flash Thinking Experimental
 */

// Standard input/output library: For functions like printf, fprintf, perror, fgets, stdin, FILE, etc.
// Used for basic input and output operations in the program, like printing messages to the console
// and reading user input.
#include <stdio.h>

// Standard library: For general utility functions like memory allocation (malloc, free),
// program termination (exit, EXIT_FAILURE), string conversions (atoi, atof),
// and other general-purpose functions.
// Used here for memory management, program exit in case of errors.
#include <stdlib.h>

// String handling library: For functions to manipulate C-style strings (character arrays),
// such as copying strings (strcpy, strncpy), comparing strings (strcmp), finding string length (strlen),
// setting memory blocks to a specific value (memset), etc.
// Essential for working with text-based messages, user names, command parsing.
#include <string.h>

// POSIX operating system API: Provides access to various operating system services.
// In network programming, it's commonly used for functions like `close()` to close file descriptors (including sockets),
// and other system-level calls.
// Used here primarily for closing the socket (`close(sockfd)`).
#include <unistd.h>

// Internet address conversion library:  Provides functions to manipulate Internet addresses
// (both IPv4 and IPv6) in various formats. Key functions include:
//  - `inet_pton` (presentation to network): Converts human-readable IP addresses (like "192.168.1.1")
//    into network byte order binary form (suitable for socket structures).
//  - `inet_ntoa` (network to ASCII): Converts network byte order binary IP addresses back into
//    human-readable dotted-decimal notation (like "192.168.1.1") for display.
//  - `htons` (host to network short): Converts a short (2-byte) integer from host byte order to network byte order.
//  - `ntohs` (network to host short): Converts a short (2-byte) integer from network byte order to host byte order.
// Used for converting IP addresses between string format and binary format needed for sockets,
// and for ensuring port numbers are in network byte order for network transmission.
#include <arpa/inet.h>

// Socket interface library:  The core header file for socket programming in Unix-like systems (including Linux, macOS).
// Defines structures and constants needed for creating, binding, connecting, sending, and receiving data over sockets.
// Key elements defined here include:
//   - `socket()` function: To create a socket (specifying address family, socket type, protocol).
//   - `bind()` function: To associate a socket with a local address (IP address and port).
//   - `sendto()` function: To send data over a UDP socket to a specific destination.
//   - `recvfrom()` function: To receive data from a UDP socket, getting sender's address information.
//   - `sockaddr_in` structure: To define IPv4 socket addresses (containing address family, port, IP address).
//   - Constants like `AF_INET` (for IPv4 address family), `SOCK_DGRAM` (for UDP sockets), `INADDR_ANY` (to bind to all local interfaces).
// This header is *essential* for all socket-based network programming in C.
#include <sys/socket.h>

// Library for synchronous non-blocking IO. Provides the `select()` function, used here to monitor if new data is
// available at a file descriptor or not, thus letting us only read from the file descriptor (blocks execution)
// when new data has been sent over the network.
#include <sys/select.h>

#define SERVER_PORT 5000 // Port for your application
#define DISCOVERY_PORT 5001 // Port for discovery messages
#define MAX_BUFFER_SIZE 1024
#define MAX_NAME_LENGTH 50
#define MAX_DISCOVERED_USERS 15 // Maximum number of discovered users we'll store

// --- Message types ---
typedef enum {
    MESSAGE_TYPE_DISCOVER_REQUEST,
    MESSAGE_TYPE_DISCOVER_RESPONSE,
    MESSAGE_TYPE_CONNECT_REQUEST, // This is now unused, but is kept here for the sake of interoperability
    MESSAGE_TYPE_FIND_REQUEST,
    MESSAGE_TYPE_FIND_RESPONSE_FOUND,
    MESSAGE_TYPE_FIND_RESPONSE_NOT_FOUND,
    MESSAGE_TYPE_UNKNOWN
} MessageType;

// --- Message struct ---
typedef struct {
    MessageType type;
    char source_name[MAX_NAME_LENGTH]; // (This is your name)
    char target_name[MAX_NAME_LENGTH]; // For FIND requests
    char path[MAX_BUFFER_SIZE];       // For FIND responses, e.g., "john->luke->mark"
} Message;

// --- Discovered user struct ---
typedef struct {
    char name[MAX_NAME_LENGTH];
    struct sockaddr_in addr; // Store address information
    int found; // Flag to indicate if user was found in discovery
} User;

// --- Global variables ---
char my_name[MAX_NAME_LENGTH]; // Program's user name
User discovered_users[MAX_DISCOVERED_USERS]; // Array to store discovered users
int discovered_user_count = 0; // Counter for discovered users
//  TODO: Add a data structure to store which computers you're connected to (e.g. an adjacency list)

// --- User facing function prototypes ---
MessageType get_message_type(char *buffer);
void process_message(Message *msg, struct sockaddr_in *client_addr, int sockfd);
void send_message(Message *msg, struct sockaddr_in *dest_addr, int sockfd);
void handle_connect_command(char *target_name, int sockfd);
void handle_find_command(char *target_name, int sockfd);

// --- Discovery function prototypes ---
void send_discovery_request(int sockfd);
void handle_discovery_response(Message *msg, struct sockaddr_in *client_addr, int sockfd);
void handle_discover_command(int sockfd); // Handler for 'discover' command
void print_discovered_users();
User* find_discovered_user_by_name(char *name);
void clear_discovered_users_list();
int add_discovered_user(char *name, struct sockaddr_in addr);

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    fd_set readable_fds; // Set of file descriptors to read from
    struct timeval timeout; // Struct for how long until 
                            // checking for new data should time out
    char buffer[MAX_BUFFER_SIZE];

    // --- Get user's name (You can change how this is set) ---
    printf("Enter your user name: ");
    fgets(my_name, MAX_NAME_LENGTH, stdin);
    my_name[strcspn(my_name, "\n")] = 0; // Remove trailing newline

    // --- Create UDP socket ---
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces

    // Enable broadcast for sending discovery messages
    int broadcastEnable = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable))) {
        perror("setsockopt (SO_BROADCAST) failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }


    // --- Bind socket to address ---
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Socket bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // --- Set up the socket for non-blocking reading --
    FD_ZERO(&readable_fds);         // Clear the file descriptor set
    FD_SET(sockfd, &readable_fds); // Add our socket to it
    timeout.tv_sec = 0;
    timeout.tv_usec = 1000;         // Set timeout period to 1 millisecond (1000 microseconds)

    printf("Program '%s' started, listening on port %d, discovery port %d\n", my_name, SERVER_PORT, DISCOVERY_PORT);

    // --- Main command loop ---
    while (1) {
        printf("> "); // Command prompt
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline

        if (strncmp(buffer, "connect ", 8) == 0) {
            char target_name[MAX_NAME_LENGTH];
            sscanf(buffer, "connect %s", target_name);
            handle_connect_command(target_name, sockfd);
        } else if (strncmp(buffer, "find ", 5) == 0) {
            char target_name[MAX_NAME_LENGTH];
            sscanf(buffer, "find %s", target_name);
            handle_find_command(target_name, sockfd);
        } else if (strncmp(buffer, "discover", 8) == 0) {
            handle_discover_command(sockfd); // Handle discovery command
        } else if (strncmp(buffer, "exit", 4) == 0) {
            printf("Exiting.\n");
            break;
        } else if (strlen(buffer) > 0) {
            printf("Unknown command. Try 'connect <name>', 'find <name>', 'discover', or 'exit'.\n");
        }

        // --- Receive and process incoming messages ---
        switch (select(sockfd + 1, &readable_fds, NULL, NULL, &timeout)) { // thanks muhammed :thumbsup:
            case -1:
                perror("Error while listening for incoming messages.");
                exit(EXIT_FAILURE);
            case 0: // 0 means select() didn't find anything new on the socket.
                break;
            default:
                recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_len);
                if (strlen(buffer) > 0) {
                    Message received_msg;
                    received_msg.type = get_message_type(buffer); // Determine message type from buffer
                    if (received_msg.type != MESSAGE_TYPE_UNKNOWN) {
                        // TODO: Deserialize the buffer into the Message struct (based on message type)
                        // For now, just print the raw message:
                        printf("Received message: %s from %s:%d\n", buffer, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                        process_message(&received_msg, &client_addr, sockfd);
                    } else {
                        printf("Unknown message type received: %s\n", buffer);
                    }
                    memset(buffer, 0, MAX_BUFFER_SIZE); // Clear buffer after processing
                }                                                                                                                                
        } 
    }
    close(sockfd);
    return 0;
}

MessageType get_message_type(char *buffer) {
    // TODO: Implement logic to determine the message type from the buffer content.
    // Messages must be formatted as strings of key-value pairs when sent over the network
    // See line 236.
    return MESSAGE_TYPE_UNKNOWN;
}

void process_message(Message *msg, struct sockaddr_in *client_addr, int sockfd) {
    switch (msg->type) {
        case MESSAGE_TYPE_FIND_REQUEST:
            // TODO: Handle FIND_REQUEST message (initiate find or forward)
            printf("Processing FIND_REQUEST for %s from %s\n", msg->target_name, msg->source_name);
            handle_find_command(msg->target_name, sockfd); 
            break;
        case MESSAGE_TYPE_FIND_RESPONSE_FOUND:
            // TODO: Handle FIND_RESPONSE_FOUND message (send back to sender or print)
            printf("Processing FIND_RESPONSE_FOUND for %s from %s, path: %s\n", msg->target_name, msg->source_name, msg->path);
            handle_find_command(msg->target_name, sockfd);
            break;
        case MESSAGE_TYPE_FIND_RESPONSE_NOT_FOUND:
            // TODO: Handle FIND_RESPONSE_NOT_FOUND message (send back to sender or print)
            printf("Processing FIND_RESPONSE_NOT_FOUND for %s\n", msg->target_name);
            handle_find_command(msg->target_name, sockfd);
            break;
        case MESSAGE_TYPE_DISCOVER_REQUEST:
            handle_discovery_response(msg, client_addr, sockfd); // Handle discovery request
            break;
        case MESSAGE_TYPE_DISCOVER_RESPONSE:
            handle_discovery_response(msg, client_addr, sockfd); // Handle discovery response
            break;
        default:
            printf("Unknown message type processing.\n");
            break;
    }
}

void send_message(Message *msg, struct sockaddr_in *dest_addr, int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // TODO: Serialize the Message struct into the buffer for sending.
    // Use the following key-value format for sending messages: 
    // "TYPE=<MESSAGE_TYPE>;SOURCE=<USER_NAME>;TARGET=<USER_NAME>
    //
    // Example:
    // "TYPE=CONNECT_REQUEST;SOURCE=john;TARGET=luke;"
    sprintf(buffer, "MESSAGE_TYPE=%d;SOURCE=%s;TARGET=%s;", msg->type, msg->source_name, msg->target_name);

    if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)dest_addr, sizeof(*dest_addr)) == -1) {
        perror("sendto failed");
    } else {
        printf("Message sent.\n");
    }
}


void handle_connect_command(char *target_name, int sockfd) {
    printf("Connect command to: %s\n", target_name);
    // TODO:
    // 1. Find the network credentials (IP) associated with the provided name
    // You should have these stored in your array of users after running `discover`
    //
    // 2. Add said user to your adjacency list/matrix.
    //
    // NOTE: There's actually no communication between computers when "connecting".
    // Since we're using UDP, we don't need to establish communication channels for
    // sending messages, so the target computer doesn't actually need to know that
    // you're "connected" to it to be able to send messages to it. The connection
    // is more of a symbolic thing, think of it as adding friends to your friends
    // list on a social media platform.

    User *target_user = find_discovered_user_by_name(target_name);
    if (target_user != NULL && target_user->found) { // Check if user is found in discovery
        // TODO: Update your connection data structure here to indicate connection to target_name
        printf("Connected to user '%s' at %s:%d.\n", target_name, inet_ntoa(*(&target_user->addr.sin_addr)), ntohs(target_user->addr.sin_port));
    } else {
        printf("User '%s' not found. Run 'discover' command first.\n", target_name);
    }
}

void handle_find_command(char *target_name, int sockfd) {
    printf("Find command for: %s\n", target_name);
    // TODO: Implement the FIND logic:
    // 1. Check if target_name is directly connected.
    // 
    // 2. If not directly connected, use either:
    //  - depth first search (send find requests to each user you're connected to first)
    //  - breadth first search (look through all your connected users first, then send find requests to each one)
    //  to find if there's a chain of connections to the user you're looking for.
    //
    // 3. Keep track of visited users to prevent loops (important for graph traversal).
    // 
    // 4. Implement logic to handle FIND_RESPONSE_FOUND and FIND_RESPONSE_NOT_FOUND messages that come back.
    //
    // HINT: You may want to break this into three functions for sending a find request, receiving a "found"
    // message and receiving a "not found" message respectively.

    // --- Placeholder: For now, just print a message ---
    printf("Initiating find for '%s' (placeholder find logic).\n", target_name);

    // --- Example of sending a FIND_REQUEST (you'll need to adapt this for your traversal) ---
    //  This part is just to demonstrate sending a FIND_REQUEST, not the full find logic
    struct sockaddr_in target_addr; // Address of a connected user (replace with actual connected user's address)
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(SERVER_PORT);
    
    if (inet_pton(AF_INET, "127.0.0.1", &target_addr.sin_addr) <= 0) { // Replace with actual connected user's IP
        perror("inet_pton failed for example FIND_REQUEST target IP");
        return;
    }

    Message find_request_msg;
    find_request_msg.type = MESSAGE_TYPE_FIND_REQUEST;
    strncpy(find_request_msg.source_name, my_name, MAX_NAME_LENGTH - 1);
    strncpy(find_request_msg.target_name, target_name, MAX_NAME_LENGTH - 1);
    send_message(&find_request_msg, &target_addr, sockfd); // Sending to a placeholder address
}

// --- Discovery Function Implementations ---

void send_discovery_request(int sockfd) {
    struct sockaddr_in broadcast_addr;
    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(DISCOVERY_PORT);
    broadcast_addr.sin_addr.s_addr = inet_addr("255.255.255.255"); // Broadcast IP

    Message discover_msg;
    discover_msg.type = MESSAGE_TYPE_DISCOVER_REQUEST;
    strncpy(discover_msg.source_name, my_name, MAX_NAME_LENGTH - 1);
    send_message(&discover_msg, &broadcast_addr, sockfd);
}

void handle_discovery_response(Message *msg, struct sockaddr_in *client_addr, int sockfd) {
    if (msg->type == MESSAGE_TYPE_DISCOVER_REQUEST) {
        printf("Discovery request received from %s, name: %s. Sending response.\n", inet_ntoa(client_addr->sin_addr), msg->source_name);
        // Respond to discovery request
        struct sockaddr_in response_addr = *client_addr;
        response_addr.sin_port = htons(DISCOVERY_PORT); // Respond to discovery port

        Message response_msg;
        response_msg.type = MESSAGE_TYPE_DISCOVER_RESPONSE;
        strncpy(response_msg.source_name, my_name, MAX_NAME_LENGTH - 1);
        send_message(&response_msg, &response_addr, sockfd);

    } else if (msg->type == MESSAGE_TYPE_DISCOVER_RESPONSE) {
        printf("Discovery response received from %s, name: %s\n", inet_ntoa(client_addr->sin_addr), msg->source_name);
        add_discovered_user(msg->source_name, *client_addr); // Add discovered user to list
    }
}

void handle_discover_command(int sockfd) {
    printf("Discover command issued. Broadcasting...\n");
    clear_discovered_users_list(); // Clear the list of discovered users before new discovery
    send_discovery_request(sockfd);
    sleep(2); // Give other users on the network time to respond
    printf("Discovery broadcast message sent.\n");
    print_discovered_users(); 
}

void print_discovered_users() {
    if (discovered_user_count == 0) {
        printf("No users discovered yet. Run 'discover' command.\n");
        return;
    }
    printf("Discovered users:\n");
    for (int i = 0; i < discovered_user_count; i++) {
        if (discovered_users[i].found) { // Only print if actually found in discovery
            printf("- %s at %s:%d\n", discovered_users[i].name, inet_ntoa(*(&discovered_users[i].addr.sin_addr)), ntohs(discovered_users[i].addr.sin_port));
        }
    }
}

User* find_discovered_user_by_name(char *name) {
    for (int i = 0; i < MAX_DISCOVERED_USERS; i++) {
        if (discovered_users[i].found && strcmp(discovered_users[i].name, name) == 0) {
            return &discovered_users[i]; // Return pointer to user if found
        }
    }
    return NULL; // Return NULL if not found
}

void clear_discovered_users_list() {
    discovered_user_count = 0;
    for (int i = 0; i < MAX_DISCOVERED_USERS; i++) {
        discovered_users[i].found = 0; // Reset found flag
        memset(&discovered_users[i].addr, 0, sizeof(struct sockaddr_in)); // Clear address
        memset(discovered_users[i].name, 0, MAX_NAME_LENGTH); // Clear name
    }
}


int add_discovered_user(char *name, struct sockaddr_in addr) {
    if (discovered_user_count < MAX_DISCOVERED_USERS) {
        // Check if user already exists (by name) - prevent duplicates if responses are resent
        if (find_discovered_user_by_name(name) == NULL) {
            strncpy(discovered_users[discovered_user_count].name, name, MAX_NAME_LENGTH - 1);
            memcpy(&discovered_users[discovered_user_count].addr, &addr, sizeof(struct sockaddr_in));
            discovered_users[discovered_user_count].found = 1; // Mark as found
            discovered_user_count++;
            return 1; // Added successfully
        } else {
            return 0; // User already in list (not added again)
        }

    } else {
        printf("Discovered users list is full. Cannot add more.\n");
        return -1; // List full
    }
}

