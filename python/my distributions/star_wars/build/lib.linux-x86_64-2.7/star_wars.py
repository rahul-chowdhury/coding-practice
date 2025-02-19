import copy
import networkx as nx
import matplotlib.pyplot as plt
def decrypt(string):              #function to decrypt string
	for i in string:
		if(i=='\n'):
			start=string.index(i)
			#print start
			break
	for j in string[start:]:
		if(j=='\n'):
			end=string.index(j,start+1)
			#print end
			break
	news=string[start:end]
	#print "news is "+news
	a=news.split('.',100)
	sentence=[]
	for i in a:
		if(len(i)==44):
			sentence.append(i)
	#print sentence
	alphabet=[['a'],['b'],['c'],['d'],['e'],['f'],['g'],['h'],['i'],['j'],['k'],['l'],['m'],['n'],['o'],['p'],['q'],['r'],['s'],['t'],['u'],['v'],['w'],['x'],['y'],['z']]
	s=" The quick brown fox jumps over the lazy dog"
	alphabet_array=[]
	for i in sentence:
		#print alphabet
		alphabet1=copy.deepcopy(alphabet)
		for k in alphabet1:
			for j in s:
				if(k[0]==j):
					alphabet1[alphabet1.index(k)].append(i[s.index(k[0])])
		#print alphabet1
		alphabet_array.append(alphabet1)
	#print alphabet_array
	#print id(alphabet1)
	#print id(alphabet)
	for k in alphabet_array:
		newstring=""
		for i in string:
			if(ord(i)<=122 and ord(i)>=97):
				for j in k:
					if(i==j[1]):
						newstring=newstring+j[0]
						break
			else:
				newstring=newstring+i
		#print newstring
		if(newstring.find("the")>0 and newstring.find("quick")>0 and newstring.find("brown")>0 and newstring.find("fox")>0 and newstring.find("jumps")>0 and newstring.find("over")>0 and newstring.find("the")>0 and newstring.find("lazy")>0 and newstring.find("dog")>0):
			break
	#print newstring
	return newstring


def display(text1):
	text2=''
	for i in text:
		if(ord(i)<=90 and ord(i)>=65):
			text2+= text1[text.index(i)].upper()
		else:
			text2+= text1[text.index(i)]
	print (text2)
	return text2
	

def getnodes(text1):
	
	start=text1.find("Rebel Bases")+12
	end=text1.find("Communication Channels")-2
	node= text1[start:end].split("\n",100)	
	return node
	
def getcoms(text1):
	
	start=text1.find("Communication Channels")+23
	end=text1.find("Messages")-2
	communication= text1[start:end].split("\n",100)
	com_channels=[]
	for i in communication:
		com_channels.append(i.split(" ",2))	
	return com_channels	
	
def graph_disp(node_list,com_channels):
	G=nx.Graph()
	for i in node_list:
		G.add_node(i) 	
	for i in com_channels:
		G.add_edge(i[0],i[1]) 	
	#nx.draw(G)
	nx.draw(G,nx.shell_layout(G),node_size=5000)
	plt.show()

	
#main console
filename=raw_input("enter the name of the file where the input is provided : ")
f = open(filename, 'r')
text=f.read()
text1=text.lower()
#print text
text1=decrypt(text1)
text1=display(text1)#displays the file in plain text
node_list=getnodes(text1)
print (node_list)
com_channels=getcoms(text1)
print (com_channels)
graph_disp(node_list,com_channels)	#displays the graph of the bases
		
		
		
		


