<img src="https://media1.tenor.com/m/Dmema-SD11UAAAAC/bogo-moment-bogo-sort.gif" align="right" width="300" />

# 🍛 task 11: Sort it out!

Den här veckans regular-uppgift handlar om att implementera några enkla sorteringsalgoritmer (och sökalgoritmer!)

Eftersom det är bra kunskap så kommer vi göra detsamma, men det kommer självklart bli lite mer spicy i standard Plus fashion.

## Koduppgift

Målet med denna veckas uppgift är att implementera tre sorteringsalgoritmer: insertion sort, selection sort och merge sort.

<details>
<summary>Klicka här för pseudokoden för alla tre algoritmer:</summary>
<br>
<pre>
# INSERTION SORT #

i ← 1
while i < length(A)
    x ← A[i]
    j ← i - 1
    while j >= 0 and A[j] > x
        A[j+1] ← A[j]
        j ← j - 1
    end while
    A[j+1] ← x
    i ← i + 1
end while
return A
</pre>
<pre>
# SELECTION SORT #

i ← 0
while i < length(A)-1
    minIndex ← i
    j ← i + 1
    while j < length(A)
        if A[j] < A[minIndex] then
            minIndex ← j
        end if
    end while
    if minIndex != i then
        swap A[i] and A[minIndex]
    end if
    i ← i + 1
end while
return A
</pre>
<pre>
# MERGE SORT (top-down) #

mergesort(A as list)
    if length(A) == 1 then return A

    left ← A[0]..A[length(A)/2]
    right ← A[length(A)/2]..A[length(A)-1]

    left ← mergesort(left)
    right ← mergesort(right)

    return merge(left, right)
end func

merge(A as list, B as list):
    C ← []

    while length(A) > 0 and length(B) > 0
        if A[0] > B[0] then
            add B[0] to the end of C
            remove B[0] from B
        else
            add A[0] to the end of C
            remove A[0] from A
        end if
    end while
    while length(A) > 0
        add A[0] to the end of C
        remove A[0] from A
    end while
    while length(B) > 0
        add B[0] to the end of C
        remove B[0] from B
    end while
    return C
end func
</pre>
</details>

> [!IMPORTANT]
> Den här veckan får du välja mellan två uppgifter att göra, listad nedan som Alternativ I och II. Du behöver bara välja och implementera ett av dem!

### Alternativ I: Sortera i Prolog

- Skapa en fil `sort.pl`, och definiera tre predikat: `insertion(I,O)`, `selection(I,O)` och `merge(I,O)`.
    - Dessa ska ta in en osorterade lista `I`, och binda den sorterade listan till `O`.
    - Predikaten ska implementera och använda sig av de tre sorteringsalgoritmerna ovan.

### Alternativ II: Sortera med grafik

- Välj **valfritt språk** och implementera de tre sorteringsalgoritmerna ovan.
- Skriv sedan någon sorts frontend för att visualisera algoritmens arbetsprocess!
    - GIFarna i regular-taskens README kan vara inspiration för hur en sådan visualisering kan se ut.
    - Terminalgrafik är acceptabelt, men satsa gärna på ett grafiskt gränssnitt!
- Implementera även **ytterligare en sorteringsalgoritm av ditt val** (ju dummare desto bättre), och visualisera den också.
- Förklara i din `docs/README.md` hur man kör ditt program!

## Teorifrågor

1. Föreställ dig en lista med 4096 element. I allra värsta fall (elementet vi söker är det allra sista vi tittar på), hur många iterationer behöver du för att hitta det sökta elementet om du använder:
    - Linjärsökning?
    - Binärsökning? (off-by-one svar är ok)
2. Förklara varför insertion sort har tidskomplexitet $O(n)$ i bästa fall, men $O(n^2)$ i sämsta fall.
2. Om du valt **Alternativ II**: Vad är tidskomplexiteten (vid bästa och sämsta fall) för din extra valda sorteringsalgoritm?