import Graphics.UI.Gtk

destroyEventHandler :: IO ()
destroyEventHandler =
  do mainQuit

button1ClickHandler :: Label ->  IO ()
button1ClickHandler lbl =
  do
    str <- labelGetText lbl
    let x = read (drop 7 str) :: Integer
    labelSetText lbl ("Score: " ++ show (1 + x))

button2ClickHandler :: Label ->  IO ()
button2ClickHandler lbl =
  do
    str <- labelGetText lbl
    let x = read (drop 7 str) :: Integer
    labelSetText lbl ("Score: " ++ show (x - 1))

main :: IO ()
main =
  do
    initGUI
    window <- windowNew
    button1 <- buttonNewWithLabel "+1"
    button2 <- buttonNewWithLabel "-1"
    label <- labelNew (Just "Score: 0")
    vBox <- vBoxNew True 4
    hBox <- hBoxNew True 4
    set window [windowDefaultWidth := 250,
                windowDefaultHeight := 200,
                windowWindowPosition := WinPosCenter,
                containerChild := vBox]
    boxPackStart hBox button1 PackGrow 0
    boxPackStart hBox button2 PackGrow 0
    boxPackStart vBox hBox PackGrow 0
    boxPackStart vBox label PackGrow 0
    on button1 buttonActivated (button1ClickHandler label )
    on button2 buttonActivated (button2ClickHandler label )
    on window objectDestroy destroyEventHandler
    widgetShow button1
    widgetShow button2
    widgetShow hBox
    widgetShow label
    widgetShow vBox
    widgetShow window
    mainGUI