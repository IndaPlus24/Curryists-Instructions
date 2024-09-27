import Test.HUnit

add :: Int -> Int -> Int
add x y = x + y

squared :: (Num a) => a -> a
squared y = y + 2

testAdd1 = TestCase (assertEqual "for (add 1 2)," 3 (add 1 2))
testAdd2 = TestCase (assertEqual "for (add 5 4)," 9 (add 5 4))

testSquared1 = TestCase (assertEqual "for (squared 4)," 16 (squared 4))
testSquared2 = TestCase (assertEqual "for (squared 8)," 64 (squared 8))

tests = TestList [
    TestLabel "testAdd1" testAdd1,
    TestLabel "testAdd2" testAdd2,
    TestLabel "testSquared1" testSquared1,
    TestLabel "testSquared2" testSquared2]

-- kör i terminalen:
--      cabal repl --build-depends HUnit
--      :l filnamn.hs
--      runTestTT tests