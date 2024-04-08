{-
-- EPITECH PROJECT, 2023
-- $RUSH
-- File description:
-- $Fourth Haskell Day
-}

import System.Environment
import System.Exit
import Execute
import Check

stringArrayToIntArray :: [String] -> [Int]
stringArrayToIntArray [] = []
stringArrayToIntArray (x:xs) = (read x :: Int) : stringArrayToIntArray xs

showResult :: ([Int], [Int]) -> [Char]
showResult (a, b)
    | b /= [] = "KO: " <> "(" <> show a <> ")" <> " (" <> show b <> ")"
    | checkSortedList a = "OK"
    | otherwise = "KO: " <> "(" <> show a <> ")" <> " (" <> show b <> ")"

errorHandling :: [String] -> [String] -> IO ()
errorHandling _ [] = return ()
errorHandling val arg
    | not (checkMove val) = exitWith (ExitFailure 84)
    | not (checkInt arg) = exitWith (ExitFailure 84)
    | otherwise = return ()

main :: IO ()
main = getLine 
    >>= \val -> getArgs 
    >>= \args -> errorHandling (words val) args
    >> return (executeFunction (words val) (stringArrayToIntArray args, []))
    >>= \r -> putStrLn (showResult r) 
