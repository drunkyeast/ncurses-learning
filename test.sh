echo $0
if [ -z $1 ]; then
	echo "please input a number"
	exit 1
elif [[ $1 =~ ^[0-9]+$ ]]; then #判断是否为数字, 妙啊.
	g++ ${1}.cpp -o ${1} -lcurses #这儿可以改成-lncurses, 不知道两者得区别.
	./${1}
else
	echo "please input correct number"
	exit 2
fi
echo "success"
