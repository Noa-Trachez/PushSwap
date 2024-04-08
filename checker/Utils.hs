{-
-- EPITECH PROJECT, 2023
-- $RUSH
-- File description:
-- $Fourth Haskell Day
-}

module Utils where

isdigit :: Char -> Bool
isdigit c = elem c "0123456789"

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition fun (x:xs)
    | fun x =
        (x: (fst (myPartition fun xs)), snd (myPartition fun xs))
    | otherwise = (fst (myPartition fun xs), x: (snd (myPartition fun xs)))

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt (x:xs)
    | (not (isdigit x)) && (x /= '-') = Nothing
    | snd (myPartition isdigit xs) == [] = Just (read (x:xs))
    | otherwise = Nothing
