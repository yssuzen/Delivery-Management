#!/usr/bin/python3
import sys

if len(sys.argv)<2:
	print("no class name detected")
	exit()
	
cl = sys.argv[1]

caps = cl.upper();
title = cl[0].upper()+cl[1:]
print(title)

result = '''
#ifndef {caps}_H
#define {caps}_H

#include <iostream>
#include <string>

using namespace std;

class {title} {{
		
	public:
		//constructor
		{title}();
		
		void print();
	
	private:
	
}};
#endif'''.format(caps = caps,title = title)

f = open(title+".h",'w')
f.write(result)
f.close()

result = '''
#include "{title}.h"

{title}::{title}(){{


}}


void {title}::print(){{

}}'''.format(title = title, cl = cl)

f = open(title+".cc",'w')
f.write(result)
f.close()
