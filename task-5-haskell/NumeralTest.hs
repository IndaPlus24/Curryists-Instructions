import Test.HUnit

romanNumeralToInteger :: String -> Integer
romanNumeralToInteger [] = 0
romanNumeralToInteger (x:y:xs)
    | x == 'M' = 1000 + romanNumeralToInteger (y:xs)
    | x == 'D' = 500 + romanNumeralToInteger (y:xs)
    | x == 'C' = 100 + romanNumeralToInteger (xs)
-- inte klar lol, fixar efter övningen


test1 = 
test2 = TestCase (assertEqual "for (romanNumeralToInteger \"XIV\")," 14 (romanNumeralToInteger "XIV"))
test3 = 

tests = TestList [
    TestLabel "testSimpleNumeral" test1,
    TestLabel "testNumeralWithSubtraction" test2,
    TestLabel "testNumeralOver1000" test3
    ]

-- kör i terminalen:
--      cabal repl --build-depends HUnit
--      :l filnamn.hs
--      runTestTT tests