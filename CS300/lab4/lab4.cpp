#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <functional>
#include <fstream>
#include <string>
#include "split.h"

using std::stack;
using std::priority_queue;
using std::queue;
using std::greater;
using std::less;
using std::string;
using std::vector;
using std::cout;

int main()
{
	vector<string> vst;
	stack<string> sstack;
	queue<string> squeue;
	priority_queue<string, vector<string>, greater<string>> sgpq;
	priority_queue<string, vector<string>, less<string>> slpq;
	string line;

	std::ifstream fin;
	fin.open("shortstory.txt");
	if (fin.fail())
	{
		std::cerr << "ERROR: \"shortstory.txt\" failed to open.\n";
		//exit(1);
	}

	while (getline(fin, line))
	{
		vst = csplit(line);
		for (vector<string>::iterator it = vst.begin(); it != vst.end(); it++)
		{
			sstack.push(*it);
			squeue.push(*it);
			sgpq.push(*it);
			slpq.push(*it);
		}
	}

	fin.close();

	cout << "\n\nUsing Stack:\n\n";
	while (!sstack.empty())
	{
		cout << sstack.top() << "  ";
		sstack.pop();
	}

	cout << "\n\nUsing Queue:\n\n";
	while (!squeue.empty())
	{
		cout << squeue.front() << "  ";
		squeue.pop();
	}

	cout << "\n\nUsing Greater Priority Queue:\n\n";
	while (!sgpq.empty())
	{
		cout << sgpq.top() << "  ";
		sgpq.pop();
	}

	cout << "\n\nUsing Less Priority Queue:\n\n";
	while (!slpq.empty())
	{
		cout << slpq.top() << "  ";
		slpq.pop();
	}

	cout << '\n';

	return 0;
}

/* Output:
Using Stack:

this  like  dog  a  on  out  Knight  a  sent  t  can  You  line  punch  the  has  that  story  dog  shaggy  the  you  tell  ll  I  time  next  good  are  you  If  now  go  to  time  s  it  Well  jokes  elephant  from  down  step  a  are  jokes  ranger  Lone  Tonto  companion  indian  trust  his  mistaking  ranger  lone  the  ranch  the  at  back  Meanwhile  pond  small  very  a  in  frog  big  a  Verily  Cohen  Leonard  to  according  stars  the  against  small  so  sky  the  against  large  so  are  We  us  on  effect  discernible  no  absolutely  have  time  of  fullnes  the  in  would  which  understand  alone  let  of  conceive  even  not  could  we  thought  a  had  comprehend  to  begin  not  could  we  intelligence  an  own  our  unlike  much  very  sun  distant  a  orbiting  world  a  on  ago  aeons  time  a  upon  Once

Using Queue:

Once  upon  a  time  aeons  ago  on  a  world  orbiting  a  distant  sun  very  much  unlike  our  own  an  intelligence  we  could  not  begin  to  comprehend  had  a  thought  we  could  not  even  conceive  of  let  alone  understand  which  would  in  the  fullnes  of  time  have  absolutely  no  discernible  effect  on  us  We  are  so  large  against  the  sky  so  small  against  the  stars  according  to  Leonard  Cohen  Verily  a  big  frog  in  a  very  small  pond  Meanwhile  back  at  the  ranch  the  lone  ranger  mistaking  his  trust  indian  companion  Tonto  Lone  ranger  jokes  are  a  step  down  from  elephant  jokes  Well  it  s  time  to  go  now  If  you  are  good  next  time  I  ll  tell  you  the  shaggy  dog  story  that  has  the  punch  line  You  can  t  sent  a  Knight  out  on  a  dog  like  this

Using Greater Priority Queue:

Cohen  I  If  Knight  Leonard  Lone  Meanwhile  Once  Tonto  Verily  We  Well  You  a  a  a  a  a  a  a  a  a  absolutely  according  aeons  against  against  ago  alone  an  are  are  are  at  back  begin  big  can  companion  comprehend  conceive  could  could  discernible  distant  dog  dog  down  effect  elephant  even  frog  from  fullnes  go  good  had  has  have  his  in  in  indian  intelligence  it  jokes  jokes  large  let  like  line  ll  lone  mistaking  much  next  no  not  not  now  of  of  on  on  on  orbiting  our  out  own  pond  punch  ranch  ranger  ranger  s  sent  shaggy  sky  small  small  so  so  stars  step  story  sun  t  tell  that  the  the  the  the  the  the  the  this  thought  time  time  time  time  to  to  to  trust  understand  unlike  upon  us  very  very  we  we  which  world  would  you  you

Using Less Priority Queue:

you  you  would  world  which  we  we  very  very  us  upon  unlike  understand  trust  to  to  to  time  time  time  time  thought  this  the  the  the  the  the  the  the  that  tell  t  sun  story  step  stars  so  so  small  small  sky  shaggy  sent  s  ranger  ranger  ranch  punch  pond  own  out  our  orbiting  on  on  on  of  of  now  not  not  no  next  much  mistaking  lone  ll  line  like  let  large  jokes  jokes  it  intelligence  indian  in  in  his  have  has  had  good  go  fullnes  from  frog  even  elephant  effect  down  dog  dog  distant  discernible  could  could  conceive  comprehend  companion  can  big  begin  back  at  are  are  are  an  alone  ago  against  against  aeons  according  absolutely  a  a  a  a  a  a  a  a  a  You  Well  We  Verily  Tonto  Once  Meanwhile  Lone  Leonard  Knight  If  I  Cohen
*/
