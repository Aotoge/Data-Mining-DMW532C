#include<bits/stdc++.h>
#include<map>
using namespace std;

ifstream fin;
double minsupport;
vector<set<string> >candidate_set;
vector<set<string> >candidate_set1;
vector<set<string> >candidate_set2;
set<string>itemset;
set<string>itemset1;
set<string>itemset2;
map<string,int>freq;
map<string,int>freq1;
map<string,int>freq2;

vector<string> wordsof(string str){
	vector<string> tmpset;
	string tmp="";
	int i=0;
	while(str[i]){
		if(isalnum(str[i]))tmp+=str[i];
		else{
			if(tmp.size()>0)
				tmpset.push_back(tmp);
			tmp="";
		}
		i++;
	}
	if(tmp.size()>0)tmpset.push_back(tmp);
	return tmpset;
}

string combine(vector<string> &arr,int miss){
	string str;
	for(int i=0;i<arr.size();i++)
		if(i!=miss)str+=arr[i]+" ";
	str=str.substr(0,str.size()-1);
	return str;
}

set<string> cloneit(set<string>&arr){
	set<string>dup;
	for(set<string>::iterator it=arr.begin();it!=arr.end();it++)dup.insert(*it);
	return dup;
}

set<string> apriori_gen(set<string>&sets,int k){
	set<string>set2;
	for(set<string>::iterator it1=sets.begin();it1!=sets.end();it1++){
		set<string>::iterator it2=it1;
		it2++;
		for(;it2!=sets.end();it2++){
			vector<string>v1=wordsof(*it1);
			vector<string>v2=wordsof(*it2);
			
			bool alleq=true;							
			for(int i=0;i<k-1&&alleq;i++)				
				if(v1[i]!=v2[i])
					alleq=false;
			if(!alleq)continue;
			
			v1.push_back(v2[k-1]);
			if(v1[v1.size()-1]<v1[v1.size()-2])
				swap(v1[v1.size()-1],v1[v1.size()-2]);
				
			for(int i=0;i<v1.size()&&alleq;i++){		
				string tmp=combine(v1,i);							
				if(sets.find(tmp)==sets.end())alleq=false;
			}			
			if(alleq)set2.insert(combine(v1,-1));
		}
	}
	return set2;
}

int main(){
	fin.open("./Data/retail.dat");
	cout<<"Minimum Support % :";						
	cin>>minsupport;
	double minsupport1,minsupport2;
	minsupport1 = minsupport;
	minsupport2 = minsupport;
	string str;
	while(!fin.eof()){
		getline(fin,str);
		vector<string>arr=wordsof(str);										
		set<string>tmpset;													 
		for(int i=0;i<arr.size();i++)tmpset.insert(arr[i]);					
		candidate_set.push_back(tmpset);
		for(set<string>::iterator it=tmpset.begin();it!=tmpset.end();it++){
			itemset.insert(*it);
			freq[*it]++;
		}
	}
	fin.close();
	for(int l = 0;l<candidate_set.size()/2;l++){
		candidate_set1.push_back(candidate_set[l]);
		for(set<string>::iterator it=candidate_set[l].begin();it!=candidate_set[l].end();it++){
			itemset1.insert(*it);
			freq1[*it]++;
		}
	}

	for(int l = candidate_set.size()/2;l<candidate_set.size();l++){
		candidate_set2.push_back(candidate_set[l]);
		for(set<string>::iterator it=candidate_set[l].begin();it!=candidate_set[l].end();it++){
			itemset2.insert(*it);
			freq2[*it]++;
		}
	}

	cout<<"No of transactions complete: "<<candidate_set.size()<<endl;
	minsupport=minsupport*candidate_set.size()/100;
	cout<<"Minimum Support Count complete: "<<minsupport<<endl;
	queue<set<string>::iterator>q;
	
	for(set<string>::iterator it=itemset.begin();it!=itemset.end();it++)
		if(freq[*it]<minsupport)q.push(it);
	while(q.size()>0){
		itemset.erase(*q.front());
		q.pop();
	}
	
	for(set<string>::iterator it=itemset.begin();it!=itemset.end();it++)			
		cout<<*it<<" "<<freq[*it]<<endl;
	
	int i=2;
	set<string>prev=cloneit(itemset);
	while(i){
		set<string>cur=apriori_gen(prev,i-1);
		if(cur.size()<1)break;
		for(set<string>::iterator it=cur.begin();it!=cur.end();it++){
			vector<string>arr=wordsof(*it);
			int tot=0;
			for(int j=0;j<candidate_set.size();j++){
				bool pres=true;													
				for(int k=0;k<arr.size()&&pres;k++)
					if(candidate_set[j].find(arr[k])==candidate_set[j].end())
						pres=false;
				if(pres)tot++;
			}
			
			if(tot>=minsupport)freq[*it]+=tot;								
			else q.push(it);
		}
		while(q.size()>0){
			cur.erase(*q.front());												
			q.pop();
		}
		
		for(set<string>::iterator it=cur.begin();it!=cur.end();it++)
			cout<<*it<<" "<<freq[*it]<<endl;
		
		prev=cloneit(cur);
		i++;
	}
	cout << endl;
	// ------------------------------------------------------------
	cout<< "Partition 1\n";
	cout<<"No of transactions partition1 : "<<candidate_set1.size()<<endl;
	minsupport1=minsupport1*candidate_set1.size()/100;
	cout<<"Minimum Support Count partition1 :"<<minsupport1<<endl;
	queue<set<string>::iterator>q1;
	
	for(set<string>::iterator it=itemset1.begin();it!=itemset1.end();it++)
		if(freq1[*it]<minsupport1)q1.push(it);
	while(q1.size()>0){															
		itemset1.erase(*q1.front());
		q1.pop();
	}
	
	for(set<string>::iterator it=itemset1.begin();it!=itemset1.end();it++)			
		cout<<*it<<" "<<freq1[*it]<<endl;
	
	i=2;
	set<string>prev1=cloneit(itemset1);
	while(i){
		set<string>cur=apriori_gen(prev1,i-1);
		if(cur.size()<1)break;
		for(set<string>::iterator it=cur.begin();it!=cur.end();it++){
			vector<string>arr=wordsof(*it);
			int tot=0;
		
			for(int j=0;j<candidate_set1.size();j++){
				bool pres=true;
				for(int k=0;k<arr.size()&&pres;k++)
					if(candidate_set1[j].find(arr[k])==candidate_set1[j].end())
						pres=false;
				if(pres)tot++;
			}
			
			if(tot>=minsupport1)freq1[*it]+=tot;									
			else q1.push(it);
		}
		while(q1.size()>0){
			cur.erase(*q1.front());												
			q1.pop();
		}
		
		for(set<string>::iterator it=cur.begin();it!=cur.end();it++)
			cout<<*it<<" "<<freq1[*it]<<endl;
		
		prev1=cloneit(cur);
		i++;
	}
	cout << endl;
	// ------------------------------------------------------------
	cout<< "Partition 2\n";
	cout<<"No of transactions partition2: "<<candidate_set2.size()<<endl;
	minsupport2=minsupport2*candidate_set2.size()/100;
	cout<<"Minimum Support Count: "<<minsupport2<<endl;
	queue<set<string>::iterator>q2;
	
	for(set<string>::iterator it=itemset2.begin();it!=itemset2.end();it++)
		if(freq2[*it]<minsupport2)q2.push(it);
	while(q2.size()>0){															
		itemset2.erase(*q2.front());
		q2.pop();
	}
	
	for(set<string>::iterator it=itemset2.begin();it!=itemset2.end();it++)			
		cout<<*it<<" "<<freq2[*it]<<endl;
	
	i=2;
	set<string>prev2=cloneit(itemset2);
	while(i){
		set<string>cur=apriori_gen(prev2,i-1);										
		
		if(cur.size()<1)break;
		for(set<string>::iterator it=cur.begin();it!=cur.end();it++){
			vector<string>arr=wordsof(*it);
			int tot=0;
			for(int j=0;j<candidate_set2.size();j++){
				bool pres=true;													
				for(int k=0;k<arr.size()&&pres;k++)
					if(candidate_set2[j].find(arr[k])==candidate_set2[j].end())
						pres=false;
				if(pres)tot++;
			}
			
			if(tot>=minsupport2)freq2[*it]+=tot;									
			else q2.push(it);
		}
		while(q2.size()>0){
			cur.erase(*q2.front());												
			q2.pop();
		}
		
		for(set<string>::iterator it=cur.begin();it!=cur.end();it++)
			cout<<*it<<" "<<freq2[*it]<<endl;
		
		prev2=cloneit(cur);
		i++;
	}
}