{-
-- EPITECH PROJECT, 2023
-- $RUSH
-- File description:
-- $Fourth Haskell Day
-}

module Check where
import Utils

checkMove :: [String] -> Bool
checkMove [] = True
checkMove (x:xs)
    | elem x
    ["sa", "sb", "sc", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"] =
        checkMove xs
    | otherwise = False

checkInt :: [String] -> Bool
checkInt [] = True
checkInt (x:xs)
    | readInt x /= Nothing = checkInt xs
    | otherwise = False

checkSortedList :: [Int] -> Bool
checkSortedList [] = True
checkSortedList (_:[]) = True
checkSortedList (x:y:xs)
    | x > y = False
    | otherwise = checkSortedList (y:xs)
