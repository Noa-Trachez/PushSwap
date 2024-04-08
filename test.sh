./push_swap `cat test.nbr` > test
echo "Move: "
cat test
echo "Checker: "
cat test | ./pushswap_checker `cat test.nbr`
rm test