#include<bits/stdc++.h>
using namespace std;

vector<set<string> >data;
set<string>minset,temp;
map<string,int>freq;
unordered_map<string,int>umap1,umap2;

vector<string> inp(string str){
	vector<string >tmp;
	istringstream ss(str); 
	string word;
	while(ss>>word){
		tmp.push_back(word);
	}
	return tmp;
}

string func(vector<string> &vec,int j){
	string str;
	for(int i=0;i<vec.size();i++)
		if(i!=j)str+=vec[i]+" ";
	str=str.substr(0,str.size()-1);
	return str;
}

set<string> copy(set<string>&arr){
	set<string>dup;
	for(set<string>::iterator it=arr.begin();it!=arr.end();it++)dup.insert(*it);
	return dup;
}

set<string>nextset(set<string>&sets,int k){
	set<string>set2;
	set<string>::iterator it2;
	for(set<string>::iterator it1=sets.begin();it1!=sets.end();it1++){
	 it2=it1;
		it2++;
		for(;it2!=sets.end();it2++){
			vector<string>v1=inp(*it1);
			vector<string>v2=inp(*it2);
			
			int flag=1;							
			for(int i=0;i<k-1&&flag;i++)				
				if(v1[i]!=v2[i])
					flag=0;
			if(!flag)continue;
			
			v1.push_back(v2[k-1]);
			if(v1[v1.size()-1]<v1[v1.size()-2])
				swap(v1[v1.size()-1],v1[v1.size()-2]);
				
			for(int i=0;i<v1.size()&&flag;i++){		
				string tmp=func(v1,i);							
				if(sets.find(tmp)==sets.end())flag=false;
			}
			
			if(flag)set2.insert(func(v1,-1));
		}
	}
	return set2;
}



int main(){
	int i,j,n,m;
    double f;
	ifstream fin;
	fin.open("./Data/retail.dat");
	cout<<"Enter min support count %"<<endl;							
	cin>>f;
	
	string str;
	set<string>::iterator it1;
	set<string>ans;
	while(!fin.eof()){
		getline(fin,str);
		vector<string>vec=inp(str);		
								
		set<string>tmpset;													
		for(int i=0;i<vec.size();i++)tmpset.insert(vec[i]);				
		data.push_back(tmpset);
		for(set<string>::iterator it=tmpset.begin();it!=tmpset.end();it++){
			//products.insert(*it);
			//temp.insert(*it);
			//freq[*it]++;
			it1=it;it1++;
           for(;it1!=tmpset.end();it1++){  
           	vector<string>vtemp;
           	vtemp.push_back((*it));
           	vtemp.push_back((*it1));
           	string tmps=func(vtemp,-1);
           	//cout<<tmps<<endl;
           	umap2[tmps]++;
           }
		}
	}
	fin.close();
	
	f=f*data.size()/100;
	cout<<data.size()<<endl;
	
	/*
	for(set<string>::iterator it=products.begin();it!=products.end();it++)
		if(freq[*it]<f)q.push(it);
	while(q.size()>0)
	{																				
		products.erase(*q.front());
		q.pop();
	}
	*/
	for(unordered_map<string,int>::iterator it=umap2.begin();it!=umap2.end();it++){
		//products.insert(*it);
		if(it->second>=f){
			cout<<it->first<<"  "<<it->second<<endl;
		}
	}
}