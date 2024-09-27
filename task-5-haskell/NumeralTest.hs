import Test.HUnit

romanNumeralToInteger :: String -> Integer
romanNumeralToInteger [] = 0
romanNumeralToInteger (x:y:xs)
    | [x,y] == "CM" = 900 + romanNumeralToInteger xs
    | [x,y] == "CD" = 400 + romanNumeralToInteger xs
    | [x,y] == "XC" = 90 + romanNumeralToInteger xs
    | [x,y] == "XL" = 40 + romanNumeralToInteger xs
    | [x,y] == "IX" = 9 + romanNumeralToInteger xs
    | [x,y] == "IV" = 4 + romanNumeralToInteger xs
romanNumeralToInteger (x:xs)
    | x == 'M' = 1000 + romanNumeralToInteger xs
    | x == 'D' = 500 + romanNumeralToInteger xs
    | x == 'C' = 100 + romanNumeralToInteger xs
    | x == 'L' = 50 + romanNumeralToInteger xs
    | x == 'X' = 10 + romanNumeralToInteger xs
    | x == 'V' = 5 + romanNumeralToInteger xs
    | x == 'I' = 1 + romanNumeralToInteger xs
    | otherwise = romanNumeralToInteger xs

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