touch readline-8.1.tar.gz
curl -ks https://ftp.gnu.org/gnu/readline/readline-8.1.tar.gz > readline-8.1.tar.gz
(tar -xf readline-8.1.tar.gz) >> t
mv readline-8.1 readline
rm -rf readline-8.1.tar.gz
mv readline includes
cd includes/readline/
(./configure --prefix=/Users/emorvan/Code/42cursus/minishell/includes/readline) >> t
make && make install && make clean
rm -rf t
cd ../../
clear
