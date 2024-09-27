import Test.HUnit

calculate :: String -> Integer
-- lägg in din funktion här!

test1 = TestCase (assertEqual "for (calculate \"1+2\")," 3 (calculate "1+2"))
test2 = TestCase (assertEqual "for (calculate \"5-1\")," 4 (calculate "5-1"))
test3 = TestCase (assertEqual "for (calculate \"3-4\")," -1 (calculate "3-4"))
test4 = TestCase (assertEqual "for (calculate \"2\")," 2 (calculate "2"))
test5 = TestCase (assertEqual "for (calculate \"2+2-3\")," 1 (calculate "2+2-3"))
test6 = TestCase (assertEqual "for (calculate \"-3+2\")," 1 (calculate "-3+2"))
--test7 = TestCase (assertEqual "for (calculate \"2+-3")," 0 (calculate "2+-3"))
--test8 = TestCase (assertEqual "for (calculate \"asdasd")," 0 (calculate "asdasd"))

tests = TestList [
    TestLabel "testAdd" test1,
    TestLabel "testSubtract" test2,
    TestLabel "testNegativeResult" test3,
    TestLabel "testNoOperations" test4,
    TestLabel "testMultipleOperations" test5,
    TestLabel "testNegativeStart" test6
    --TestLabel "testTwoOperationsInARowIsValid" test7,
    --TestLabel "testTextIsInvalid" test8
    ]

-- kör i terminalen:
--      cabal repl --build-depends HUnit
--      :l filnamn.hs
--      runTestTT tests