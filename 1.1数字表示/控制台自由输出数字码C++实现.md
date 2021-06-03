@[TOC](控制台输出数字)

# 前言
本博客使用C++ 编程实现代码，使用VS2015编译运行，由于本人并不是C++专业编程人员，代码处理方面有所欠缺，如果有更好的实现建议，欢迎留下宝贵的评论，当然我在文末也会有一点我对本实现方式的思考和总结。
**具体题目并非本人原创，实现思路及代码均为本人思考后得出，侵删**


#  题目要求
实现在控制台上使用 * 打印输入的任意两位数，有如下要求：
1. 可以实现对输入的简单检查，确保输入是两位数字
2. 两个数字的列宽默认保持一致，但可以修改打印表示的列宽
3. 两个数字之间间隔为一列

4. 不得使用硬编码，要求使用循环实现打印，自上而下将字符分为五个部分，下面是每个部分的函数原型：*segment_one(int
digit)、segment_two(int digit)、segment_three(int digit)、segment_four(int digit)、
segment_five(int digit)，其中，参数digit为数字（0~9)；* 
其中第二段和第四段默认打印三行。
**下面是一个打印的范例**
![打印输出](https://img-blog.csdnimg.cn/20210522091710253.png#pic_center)
# 简单分析
**在实际编程时，面对问题，我认为最好的是先提前分析问题，在有思路之后，再进行编程，我认为这样的效率是很高的**
## 首先
题目要求的是要打印两个数字，这是最主要的，我们就要考虑，数字该如何打印输出，为了简单起见，我先说一下如果仅仅要打印一个数字，还是要使用题目要求的是个五个部分的函数，循环实现，那就将一个数字自上而下的氛围五个部分，每个部分要单独输出，最后再拼接再一起。就像这样：

![演示](https://img-blog.csdnimg.cn/20210522093124377.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ1OTY2MjAx,size_16,color_FFFFFF,t_70#pic_center)
这样看的话，其实每个部分的打印都很简单了，比如第一、三、五部分都是很相似的，都是只要使用一个for循环就可以实现的，那如果要是不同数字，那就只要根据不同的数字，每个部分取相似的，都放在一起就可以了， 可以使用switch-case语句来分组，也可以使用if-else if语句来区分。也就是说，可以根据数字五个部分相同的地方进行分类，这样对每个类别、每个部分进行输出就可以了。
## 进一步思考：
想到这，如果要直接输出一个数字是不是已经有思路了，但是我们现在要做的是要同时输出两个数字（并排输出），我们肯定不可以在输出一个数字之后再输出另外一个数字，因为输出光标是无法在回到上面去，继续输出的另外一个数字的。所以这就要我们在输出数字的时候，要一行一行的输出。
## 如何实现呢：

 我们可以从分成的五个部分入手，一个部分一个部分的输出
1. 第一部分：第一个数字的segment——one， 然后输出一个空格，作为两个数字之间的分割，第二个数字的segment_one,这样两个数字的第一部分就已经输出完成了，下面输出一个换行符，就可以进行第二部分的输出了。
2. 第二部分：我们真的可以将第二部分直接作为一个整体放在segment——two中吗？如果是这样的话，那么在输出完第一个数字之后，我们必然不可能再让光标回到上面，接着输出第二个数字的第二部分，**所以我们可以将segment_two只输出一行**，在 调用该函数时，调用三次，就可以实现每一行一个换行了（也可以理解为在调用segment_two函数时使用for循环）这是一种方式，**我会在下面的总结反思时提到另外一种方法，我个人认为这种方法是很不错的**，如果是这输出一行的话，这样函数的调用方式就和第一部分基本一致了，我会在下面具体的代码实现中再详细解释。
3. 第三部分：其实下面的部分基本都是上面一二部分的重复了，第一、三、五部分原理是基本一样的，因为都是在一行中进行输出，第二、四、部分是基本一样的，都是要输出三行数据。这样要输出两个数字的任务就可以基本实现了。

---
好了截至现在，基本的实现原理已经清楚了，剩下的就是代码实现了，如果可以完全理解上面的实现原理，那么现在应该就可以快速的进行编程调试了，再稍微优化一下，就可以实现完整的函数功能了。
**下面就是详细的代码解释了，如果已经实现了，也可以对照参考下**
# 代码实现
## 输入检查
题目中是明确要求需要进行输入检查的，当然我们再日常编程时，我也是推荐经常对代码进行输入检查、类型检查，可以算是一个习惯吧，以后在实际编程中，可以减少出现莫名其妙的bug，这里我就简单的进行一个输入检查，我使用了一个while循环来实现，下面时获取输入的具体代码

```cpp
int main()
{
	int num;
	cout << "请输入一个数字 :（10-99）" ;
	cin >> num ;
	//cout << "num=" << num << endl;
	
	while(num < 10||num > 99)
	{
		cout << "输入错误，请注意输入数字范围(10-99):" ;
		cin >> num;
	}
	cout <<"您输入的数字为 : " << num << endl;
	
	int a,b;
	a=num/10;
	b=num%10;

	//cout << "a=" << a << endl;
	//cout << "b=" << b << endl;

	cout << "您输入的整数为：" << endl;
	cout << endl;
	printnum(a,b);
	cout << endl;

	return 0;
}
```
这是我的main函数部分，这里使用while循环来实现简单的输入检查，只要输入的是不恰当的数字，那就永远无法出循环，这里唯一要注意的就是要记得对输入数据检查的更新，万不可进行死循环，下面的printnum（）函数就是我自己构建的，用于输出的一个函数了。
**关于输入检查** 这里使用的while循环来进行输入检查其实有致命的缺陷，它仅仅 可以实现对int类型的检查，如果用户在输入时输入了一个char型的数据，由于没有强制类型转换，while会进入死循环，就会出现问题！！
*所以我会在后面的思考反思部分，给出一个更加完美一点的输入检查，实现对任何输入类型的检查报错，并且可以随时退出该程序。*
## 五个部分的函数
下面的就是题目要求的5个部分的函数，我使用的是if-else if来进行逻辑判断，当然也可以使用switch-case来进行选择，这个基本一致，下面是五个函数：我在代码中已经有相关的较为详细的注释了，可以参考

```cpp
void segment_one_0()
{
	for (int i = 0; i<col; i++)
	{
		cout << "*";
	}
}

void segment_one(int digit)
{
	//区分不同的情况，在第一段函数中，对于不同的数字要打印不同的方式
	if (digit == 0 || digit == 2 || digit == 3 || digit == 5 || digit == 6 || digit == 7 || digit == 8 || digit == 9)
	{
		segment_one_0();  //可以将这样类似的for循环输出语句都变为函数引用
	}
	else if (digit == 1)
	{
		for (int i = 0; i<col - 1; i++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else if (digit == 4)
	{
		cout << "*";
		for (int i = 0; i<col - 2; i++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else
	{
		cout << "Error!" << endl;
	}
	//如果有情况遗漏，则打印错误信息		
}

void segment_two(int digit)
{
	//第二四部分是较为难实现的，因为是两个数字，需要在同一行中实现，就不能是简单的挨个输出数字，
	//所以我采用的是每一行输出一部分内容，然后在整个的打印函数中，将其整合起来
	if (digit == 1 || digit == 2 || digit == 3)
	{
		for (int j = 0; j<col - 1; j++)
		{
			cout << " ";
		}
		cout << "*";  //仅仅打印一行
	}
	else if (digit == 0 || digit == 4 || digit == 8 || digit == 9)
	{
		cout << "*";
		for (int j = 0; j<col - 2; j++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else if (digit == 5 || digit == 6)
	{
		cout << "*";
		for (int j = 0; j<col - 1; j++)
		{
			cout << " ";
		}
	}
	else if (digit == 7)
	{
		for (int j = 0; j<col - 1; j++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else
	{
		cout << "Error!" << endl;
	}
}

void segment_three(int digit)
{//第三部分的实现和第一部分的实现是很类似的
	if (digit == 2 || digit == 3 || digit == 4 || digit == 5 || digit == 6 || digit == 8 || digit == 9)
	{
		for (int i = 0; i < col; i++)
		{
			cout << "*";
		}
	}
	else if (digit == 1 || digit == 7)
	{
		for (int i = 0; i < col - 1; i++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else if (digit == 0)
	{
		cout << "*";
		for (int i = 0; i < col - 2; i++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else
	{
		cout << "Error!" << endl;
	}
}

void segment_four(int digit)
{
	if (digit == 1 || digit == 3 || digit == 4 || digit == 5 || digit == 7 || digit == 9)
	{
		for (int j = 0; j<col - 1; j++)
		{
			cout << " ";
		}
		cout << "*";

	}
	else if (digit == 0 || digit == 6 || digit == 8)
	{
		cout << "*";
		for (int j = 0; j<col - 2; j++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else if (digit == 2)
	{

		cout << "*";
		for (int j = 0; j<col - 1; j++)
		{
			cout << " ";
		}
	}
	else
	{
		cout << "Error!" << endl;
	}
}

void segment_five(int digit)
{
	if (digit == 0 || digit == 2 || digit == 3 || digit == 5 || digit == 6 || digit == 8)
	{
		for (int i = 0; i < col; i++)
		{
			cout << "*";
		}

	}
	else if (digit == 1 || digit == 4 || digit == 7 || digit == 9)
	{
		for (int i = 0; i < col - 1; i++)
		{
			cout << " ";
		}
		cout << "*";
	}
	else
	{
		cout << "Error!";
	}
}
```
## 函数整合
具体的注释在代码中有解释，其中需要重点关注是segment_two和segment_four ，这两个函数都是仅仅输出一行，而不是将第二部分全部打印输出，这样就可以实现**两个数字并排打印了**，下面是如何调用这五个部分的函数printNum（），是完整代码：

```cpp
void printnum(int a,int b)
{
	//为了确保可以在一行里打印两个数字，就轮流调用函数
	segment_one(a);
	cout << " ";
	segment_one(b);
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		segment_two(a);
		cout << " ";
		segment_two(b);
		cout << endl;  //回车一定是在行末打印，否则就会出现错误
	}//第二四部分是基本类似的，其实都不是直接打印整个部分，而是每次调用都只打印一行内容，在这里整合

	segment_three(a);
	cout << " ";
	segment_three(b);
	cout << endl;

	for (int j = 0; j < size; j++)
	{
		segment_four(a);
		cout << " ";
		segment_four(b);
		cout << endl;
	}
	
	segment_five(a);
	cout << " ";
	segment_five(b);
	cout << endl;
}
```

好了，截止目前，关于具体的实现代码就已经实现了，当然，在现在看来，这个实现还是略显粗糙的，还有很多可以改进的地方，下面我就上面提到的，提出一点改进，使程序更加完美。
***我也会在文末，给出我完整的实现代码。***
# 思考反思
## 输入检查
在上文提到，使用while进行数据输入检查是有缺陷的，如果输入的不是int型数据了，会直接进入死循环，那么该如何避免这样的问题？
既然不使用while循环，我们要实现重复的错误输入，还是要使用循环，那么for循环是否是可以实现的呢？for也是可以实现的死循环的，只要不设置出口就可以了；既然有了死循环就可以进行无限的错误输入了，直到输入正确才可以继续运行，而且，如果在for循环的条件判断中，如果输入的数据类型不是设定的类型，那么for循环中的cin是不会处理的，仅仅会处理该输入数据的下一个，也就是输入数据后面的 回车键 ，就可以实现退出了，具体实现原理，可以参考这篇博客：[侵删](https://blog.csdn.net/zk_j1994/article/details/72355753)
下面是我实现输入检查的完整的main函数部分：

```cpp
int main()
{
	int num;
	/*cout << "请输入一个数字 :（10-99）" ;
	cin >> num ;
	//cout << "num=" << num << endl;
	
	while(num < 10||num > 99)
	{
		cout << "输入错误，请注意输入数字范围(10-99):" ;
		cin >> num;  //输入检查
	}*/

	string const prompt = "请输入一个数字（10-99）[按任意字符退出] :";
	string const out_range = "输入错误！";
	for (int i = 0; cout << prompt, cin>>i; )  
	{//这里的for是死循环，只要输入的是数字，永远不会跳出循环，只要输入字符，就可以跳出循环结束
		if (i < 10 || i>99)
		{
			cout << out_range;
			continue;  //可以跳出本次for循环，进入下一次for循环
			//如果输入的是错误的数字，则继续输入
		}
		num = i;


		cout << "您输入的数字为 : " << num << endl;

		int a, b;
		a = num / 10;
		b = num % 10;

		//cout << "a=" << a << endl;
		//cout << "b=" << b << endl;

		cout << "您输入的整数为：" << endl;
		cout << endl;
		printnum(a, b);
		cout << endl;

	}

	return 0;
}
```
下面是使用条件判断语句实现的输出效果：
![输入检查](https://img-blog.csdnimg.cn/20210523170219673.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ1OTY2MjAx,size_16,color_FFFFFF,t_70#pic_center)

## 打印输出
上面提到，在代码中我采用的是将第二 第四部分函数写为仅仅输出一行，然后再通过多次调用，实现输出多行，这里再提供另外一个思路：我们可以在segment_two 函数中设置一个标志量，用该变量作 计数 ，当计数满足要输出回车的条件时，通过一个if判断，来实现输出一个回车，达到在合适的时候换行的目的，关于这部分我就不提供具体的实现代码，可以自由实现。
## 整点花活
既然该程序可以用 * 来打印出数字，那么我们是不是可以用其他符号来实现打印数字呢？
而且可以改程序可以实现打印任意两位数，我们是否可以实现打印三位数呢？（比如520,521），我也稍微尝试了下，发现是完全可以的，只是如果要实现用函数进行输出打印的话，要注意汉字的大小是两个字符，就不可以使用char来进行存储，可以使用string来存储，同时一个汉字相当于两个空格，这个在打印空格时也要注意，其他的实现就较为简单了，下面来看一下我实现的效果：
![字符输出](https://img-blog.csdnimg.cn/20210523170757719.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ1OTY2MjAx,size_16,color_FFFFFF,t_70#pic_center)实现打印的可以是任何文字，由于目前代码还比较粗糙，仅仅可以打印521这一个数字，要添加其他数字也是可以的，不会很复杂，而且本输出就仅仅作为演示，如果有其他想法可以继续修改。
***我会在后续把这两个的完整项目代码上传至GitHub，链接附在下面，欢迎指正**
# 总结
到现在，我们就已经实现了完整的功能，对于本题来说，它没有复杂的数据结构，主要练习的是建模和代码实现能力，可以作为熟悉C++语法的练习题，提高自己编程解决问题的能力。
# 最后：完整代码
# 最后的最后
**感谢观赏，一起提高，慢慢变强。**
