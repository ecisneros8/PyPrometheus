set -x

cd ../build
make realclean all
cd ../run
sh link.sh
