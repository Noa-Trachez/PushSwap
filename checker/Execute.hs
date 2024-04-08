{-
-- EPITECH PROJECT, 2023
-- $RUSH
-- File description:
-- $Fourth Haskell Day
-}

module Execute where
import Functions
import TypeDef

getMoves :: [([Char], Lists -> Lists)]
getMoves = [("sa", sa), ("sb", sb), ("sc", sc),
    ("pa", pa), ("pb", pb),
    ("ra", ra), ("rb", rb), ("rr", rr),
    ("rra", rra), ("rrb", rrb), ("rrr", rrr)]

findMove :: String -> [([Char], Lists -> Lists)] -> (Lists -> Lists)
findMove _ [] = (\(_, _) -> ([], []))
findMove str ((a, b):xs)
    | str == a = b
    | otherwise = findMove str xs

executeFunction :: [String] -> Lists -> Lists
executeFunction [] l = l
executeFunction (x:xs) l = executeFunction xs ((findMove x getMoves) l)
