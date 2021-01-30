cc = gcc #定义变量不需要带引号
targetFile = test.o bar.o
bin=test

$(bin):$(targetFile)
	$(cc) -o $@ $^ # $@代表依赖关系中的目标文件也就是$(bin)=test,$^代表依赖文件列表也就是$(targetFile)=test.o bar.o
%.o:%.c
	$(cc) -c  $< # $< 代表当前目录下所有 %.c文件的集合
/PHONY:clean
clean:
	rm -rf $(targetFile) $(bin)