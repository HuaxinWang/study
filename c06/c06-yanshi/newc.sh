if test $# -gt 0
then
	if test -f $1
	then
		echo "文件已存在"
	else
		touch $1
		echo "#include <stdio.h>" >> $1
		echo " " >> $1
		echo "int main()" >> $1
		echo "{" >> $1
		echo "	" >> $1
		echo "	return 0;" >> $1
		echo "}" >> $1
	fi
else
	echo "请输入文件名"
fi




