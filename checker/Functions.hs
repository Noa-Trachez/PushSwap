{-
-- EPITECH PROJECT, 2023
-- $RUSH
-- File description:
-- $Fourth Haskell Day
-}

module Functions where
import TypeDef

sa :: Lists -> Lists
sa ((x:y:xs), b) = ((y:x:xs), b)
sa l = l

sb :: Lists -> Lists
sb (a, (x:y:xs)) = (a, (y:x:xs))
sb l = l

sc :: Lists -> Lists
sc (a, b) = sb (sa (a, b))

ra :: Lists -> Lists
ra ((x:xs), b) = (xs <> [x], b)
ra l = l

rb :: Lists -> Lists
rb (a, (x:xs)) = (a, xs <> [x])
rb l = l

rr :: Lists -> Lists
rr l = rb (ra l)

rra :: Lists -> Lists
rra ([], b) = ([], b)
rra (a, b) = (last a: init a, b)

rrb :: Lists -> Lists
rrb (a, []) = (a, [])
rrb (a, b) = (a, last b: init b)

rrr :: Lists -> Lists
rrr l = rrb (rra l)

pa :: Lists -> Lists
pa (a, (x:xs)) = (x: a, xs)
pa l = l

pb :: ([Int], [Int]) -> ([Int], [Int])
pb ((x:xs), b) = (xs, x: b)
pb l = l
