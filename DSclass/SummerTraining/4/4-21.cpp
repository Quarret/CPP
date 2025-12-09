 #include<string>
 #include<iostream>
 #include<sstream>
 #include<stack>
 #include<vector>
 using namespace std;
 
 int ball_score(char a){
 	 switch(a){
 	 	case 'r':{
 	 		return 1;
			break;
		  }
		case 'y':{
 	 		return 2;
			break;
		  }
		case 'g':{
 	 		return 3;
			break;
		  }
		case 'c':{
 	 		return 4;
			break;
		  }
		case 'b':{
 	 		return 5;
			break;
		  }
		case 'p':{
 	 		return 6;
			break;
		  }
		case 'B':{
 	 		return 7;
			break;
		  }	
		  default:{
		  	return 0;
			break;
		  }  
	  }
 } 
 
 int ball[8];
 int ball_num(char a){
 	return ball[ball_score(a)];
 }
	
 void init_ball_num(){
	ball[1]=15;
	for(int i=2;i<=7;i++) ball[i]=1;
 } 
 
 int A_100_times=0,B_100_times=0;//（单杆得分是指选手一次连续击打所得分数之和）!!! 【 不是一局的总分！！！】 
 int A_score,B_score; 
 
 void A_red();
 void B_red();
 void A_color(char fa);
 void B_color(char fa);
 
 int A_hit_score=0,B_hit_score=0; 
 
 
 void A_red(){
 	if(ball_num('r')==0) {
	 	A_color('r');     //红球没了，只能是按顺序击打彩球 
 		return; 
	 } 
 	
 	if(B_hit_score>=100){
 		//cout<<endl<<endl<<"B_MARK__100"<<endl<<endl;
 		B_100_times++; 
 		B_hit_score=0;
		//cout<<endl<<"@@@@@a_red: "<<A_hit_score<<"  "<<B_hit_score<<endl;
	 }
 	
 	 string condition;
	 getline(cin,condition); 
 	
 	if(condition=="-1")  {
 		
 		if(A_hit_score>=100) A_100_times++;   //在自己连续击打的时候结束 
 		A_hit_score=0;B_hit_score=0;//初始化双方连续击打分 
 		
	 	cout<<A_score<<":"<<B_score<<endl; 
		 return; //本局比赛结束；
	 } 
 	
 	if(condition=="NULL") {//打空了  犯规 
		B_score+=4; 
		B_hit_score=0;
		B_red(); 
		} else if(condition.find(' ')!=string::npos ){   //有打球，有落入 
			string hit,drop;
			hit=condition.substr(0,condition.find(' '));
			drop=condition.substr(condition.find(' ')+1,condition.size() - condition.find(' '));
 
			int flag1=1;
			int maxi1=4;
			for(int i=0;i<hit.size() ;i++){    //看击打有没有犯规  
				if(hit[i]!='r') flag1=0;
				if(maxi1<ball_score(hit[i])) maxi1=ball_score(hit[i]);
			}
			
			int flag2=1;
			int maxi2=4;         //看落球有没有犯规 
			for(int i=0;i<drop.size() ;i++){
				if(drop[i]!='r'){
					if(drop[i]<'0'||drop[i]>'9'){
						flag2=0;
					}
				}
				if(maxi2<ball_score(drop[i])) maxi2=ball_score(drop[i]);
			} 
			
			//不管犯不犯规  红球落入了就得减去 
			int r_num=0;
				if(drop.find('r')!=string::npos ){//有红球落入 
					int pos=drop.find('r');
					vector<int> v;
					for(int i=pos+1;i<drop.size() ;i++) {
						if(drop[i]>='0'&&drop[i]<='9') v.push_back(drop[i]-'0'); 
					}
					if(v.size()==1) {
						r_num+=v[0];
						ball[ball_score('r')]-=r_num; 
					}
					else {
						r_num+=v[0]*10 + v[1];
						ball[ball_score('r')]-=r_num; 
					}
				}   
	
			if(flag1==0 || flag2==0){   //两样都犯规了  比较出最大分数给对方加上  计算掉入的红球
				B_score+=max(maxi1,maxi2);
				B_hit_score=0;
				B_red();
			}else {        //没有犯规 
				A_hit_score+=r_num;
				A_score+=r_num;
				A_color('f'); //常规自由球 
			}
		}else {   //只打了球，没落入 
			int flag=1;
			for(int i=0;i<condition.size() ;i++){
				if(condition[i]!='r'){
					flag=0;
				} 
			}
			if(flag==1){  //打得全是红球  因为没落入 所以没分  红球也没有少 
				B_hit_score=0;
				B_red();
			}else{        //打到了其他球， 犯规 对方加分 
				int maxi3=4;
				for(int i=0;i<condition.size() ;i++){
					if(ball_score(condition[i])>maxi3) maxi3=ball_score(condition[i]);
				} 
				B_score+=maxi3; 
				B_hit_score=0;
				B_red(); 
			}
		}
 }
 
 void A_color(char fa){     //要判断当前打自由彩球还是顺序彩球   记录上一球 
 	
	 if(B_hit_score>=100){ 
	 	//cout<<endl<<endl<<"B_MARK__100"<<endl<<endl;
 		B_100_times++; 
 		B_hit_score=0;
		//cout<<endl<<"@@@@@a_color: "<<A_hit_score<<"  "<<B_hit_score<<endl;
	 }
	
 	string condition;
	getline(cin,condition); 
 	
 	if(condition=="-1" ){
 		
 		if(A_hit_score>=100) A_100_times++;   //在自己连续击打的时候结束 
 		 A_hit_score=0;B_hit_score=0;
 		
 		cout<<A_score<<":"<<B_score<<endl;
		 return; //本局比赛结束；
	 }
 	
 	if(fa=='f') {  //自由彩球 
	    if(condition=="NULL") {                          //打空了  犯规 
			B_score+=4; 
			B_hit_score=0;
			B_red(); 
		} else if(condition.find(' ')!=string::npos ){   //有打球，有落入			
			string hit,drop;
			hit=condition.substr(0,condition.find(' '));
			drop=condition.substr(condition.find(' ')+1,condition.size() - condition.find(' '));
			
			int r_num=0; //无论如何，只要有红球落入，就要计算 
				if(drop.find('r')!=string::npos ){//有红球落入 
					int pos=drop.find('r');
					vector<int> v;
					for(int i=pos+1;i<drop.size() ;i++) {
						if(drop[i]>='0'&&drop[i]<='9') v.push_back(drop[i]-'0'); 
					}
					if(v.size()==1) {
						r_num+=v[0];
						ball[ball_score('r')]-=r_num; 
					}
					else {
						r_num+=v[0]*10 + v[1];
						ball[ball_score('r')]-=r_num; 
					}	
				}
			
			int flag1=1;  //看击打有没有犯规 
			int maxi1=4;
			if(hit=="r"||hit.size()>1){
				flag1=0;
				for(int i=0;i<hit.size();i++){
					if(ball_score(hit[i])>maxi1) maxi1=ball_score(hit[i]);
				}	
			} 
			
			if(flag1==0){//击球犯规，在击球和落球里面找个最大的给对方加分 
				for(int i=0;i<drop.size();i++){
					if(ball_score(drop[i])>maxi1) maxi1=ball_score(drop[i]);
				} 
				B_score+=maxi1;
				B_hit_score=0;
				B_red();
				
			} else{       //击球没犯规，只打了一个彩球 
				if(drop==hit){      //落球也完全一样 ,加分继续打红球 
					A_hit_score+=ball_score(drop[0]);
					A_score+=ball_score(drop[0]); 
					A_red(); 
				}else{              //落球多了些东西，给对方加最大分 
					int maxi3=4; 
					for(int i=0;i<hit.size();i++){
						if(ball_score(hit[i])>maxi3) maxi3=ball_score(hit[i]);
					}
					for(int i=0;i<drop.size();i++){
						if(ball_score(drop[i])>maxi3) maxi3=ball_score(drop[i]);
					} 
					B_score+=maxi3;
					B_hit_score=0;
					B_red(); 
				} 
			}	
		} else{//只打了球，没落入 
			if(condition=="r"||condition.size() >1) {//打到了多个球或者打到了红球   没进 
				int maxi=4;
				for(int i=0;i<condition.size() ;i++){
					if(ball_score(condition[i])>maxi)  maxi=ball_score(condition[i]);
				} 
				B_score+=maxi;
				B_hit_score=0;
				B_red();
			} else{                                  //打到单个彩球 但没进 
				B_hit_score=0;
				B_red();
			} 
		} 
		
	} else {       //顺序彩球  
		string sub="rygcbpB";
		string goal=sub.substr(sub.find(fa)+1,1); 
		char c_goal=sub[sub.find(fa)+1 ]; 
		
		if(condition=="NULL") {                          //打空了,犯规,对方加分，按顺序打 
			B_score+=4; 
			B_hit_score=0;
			B_color(fa); 
		} else if(condition.find(' ')!=string::npos ){   //有打球，有落入		
		
			string hit,drop;
			hit=condition.substr(0,condition.find(' '));
			drop=condition.substr(condition.find(' ')+1,condition.size() - condition.find(' '));
			
			if( hit==goal && hit==drop )   { //目标， 击打，落入都一样  
				A_hit_score+=ball_score(c_goal);
				A_score+=ball_score(c_goal);//分数增加 
				ball[ball_score(c_goal)]--; //球数减少 
				A_color(c_goal);            //继续按照顺序击打 
			} else{//击球或者落球犯规，在所有球里面找最大的 （包括目标球） 
				int maxi3=max(4,ball_score(c_goal)); 
				for(int i=0;i<hit.size();i++){
					if(ball_score(hit[i])>maxi3) maxi3=ball_score(hit[i]);
				}
				for(int i=0;i<drop.size();i++){
					if(ball_score(drop[i])>maxi3) maxi3=ball_score(drop[i]);
				}
				B_score+=maxi3;
				B_hit_score=0;
				B_color(fa);
			}
		}else {                                           //有打球，没落入 
			string hit=condition;
			if(hit==goal){
				B_hit_score=0;
				B_color(fa);
			}else {
				int maxi=4;
				for(int i=0;i<hit.size();i++){
					if(ball_score(hit[i])>maxi) maxi=ball_score(hit[i]);
				}
				B_score+=maxi;
				B_hit_score=0;
				B_color(fa);
			}	
		}
	}
 	
 } 
 
 void B_red(){
 	if(ball_num('r')==0) {
	 	B_color('r');     //红球没了，只能是按顺序击打彩球 
 		return; 
	 } 
 
 	if(A_hit_score>=100){
 		//cout<<endl<<endl<<"A_MARK__100"<<endl<<endl;
 		A_100_times++; 
 		A_hit_score=0;
		//cout<<endl<<"@@@@@b_red: "<<A_hit_score<<"  "<<B_hit_score<<endl;
	 }
 	
 	 string condition;
	 getline(cin,condition); 
 	
 	if(condition=="-1")  {
 		
 		if(B_hit_score>=100) B_100_times++;   //在自己连续击打的时候结束 
 		 A_hit_score=0;B_hit_score=0;
 		
	 	cout<<A_score<<":"<<B_score<<endl; 
		 return; //本局比赛结束；
	 } 
 	
 	if(condition=="NULL") {//打空了  犯规 
		A_score+=4; 
		A_hit_score=0;
		A_red(); 
		} else if(condition.find(' ')!=string::npos ){   //有打球，有落入 
			string hit,drop;
			hit=condition.substr(0,condition.find(' '));
			drop=condition.substr(condition.find(' ')+1,condition.size() - condition.find(' '));
			//cout<<endl<<"@@@@"<<hit<<"@@"<<drop<<endl;
			int flag1=1;
			int maxi1=4;
			for(int i=0;i<hit.size() ;i++){    //看击打有没有犯规  
				if(hit[i]!='r') flag1=0;
				if(maxi1<ball_score(hit[i])) maxi1=ball_score(hit[i]);
			}
			
			int flag2=1;
			int maxi2=4;         //看落球有没有犯规 
			for(int i=0;i<drop.size() ;i++){
				if(drop[i]!='r'){
					if(drop[i]<'0'||drop[i]>'9'){
						flag2=0;
					}
				}
				if(maxi2<ball_score(drop[i])) maxi2=ball_score(drop[i]);
			} 
			
			//不管犯不犯规  红球落入了就得减去 
			int r_num=0;
				if(drop.find('r')!=string::npos ){//有红球落入 
					int pos=drop.find('r');
					vector<int> v;
					for(int i=pos+1;i<drop.size() ;i++) {
						if(drop[i]>='0'&&drop[i]<='9') v.push_back(drop[i]-'0'); 
					}
					if(v.size()==1) {
						r_num+=v[0];
						ball[ball_score('r')]-=r_num; 
					}
					else {
						r_num+=v[0]*10 + v[1];
						ball[ball_score('r')]-=r_num; 
					}
				}   
	
			if(flag1==0&&flag2==0){   //两样都犯规了  比较出最大分数给对方加上  计算掉入的红球
				A_score+=max(maxi1,maxi2);
				A_hit_score=0;
				A_red();
			}else if(flag1==0){     //击球犯规      @@@@@@@@@@@@@@存疑 
				A_score+=max(maxi1,maxi2);
				A_hit_score=0;
				A_red();
			}else if(flag2==0){     //落球犯规 
				A_score+=max(maxi1,maxi2);
				A_hit_score=0;
				A_red();
			}else {        //没有犯规 
				B_hit_score+=r_num;
				B_score+=r_num;
				B_color('f'); //常规自由球 
			}
		}else {   //只打了球，没落入 
			int flag=1;
			for(int i=0;i<condition.size() ;i++){
				if(condition[i]!='r'){
					flag=0;
				} 
			}
			
			if(flag==1){  //打得全是红球  因为没落入 所以没分  红球也没有少 
				A_hit_score=0;
				A_red();
			}else{        //打到了其他球， 犯规 对方加分 
				int maxi3=4;
				for(int i=0;i<condition.size() ;i++){
					if(ball_score(condition[i])>maxi3) maxi3=ball_score(condition[i]);
				} 
				A_score+=maxi3; 
				A_hit_score=0;
				A_red(); 
			}
		}
 }
 
 void B_color(char fa){
 	
 
 
	if(A_hit_score>=100){
		//cout<<endl<<endl<<"A_MARK__100"<<endl<<endl;
 		A_100_times++; 
 		A_hit_score=0;
		//cout<<endl<<"@@@@@b_color: "<<A_hit_score<<"  "<<B_hit_score<<endl; 
	 }
	
 	 string condition;
	 getline(cin,condition); 
 	
 	if(condition=="-1" ){
 		
 		if(B_hit_score>=100) B_100_times++;   //在自己连续击打的时候结束 
 		 A_hit_score=0;B_hit_score=0;
 		
 		cout<<A_score<<":"<<B_score<<endl;
		 return; //本局比赛结束；
	 }
 	
 	if(fa=='f') {  //自由彩球 
	    if(condition=="NULL") {                          //打空了  犯规 
			A_score+=4; 
			A_hit_score=0;
			A_red(); 
			
		} else if(condition.find(' ')!=string::npos ){   //有打球，有落入			
			string hit,drop;
			hit=condition.substr(0,condition.find(' '));
			drop=condition.substr(condition.find(' ')+1,condition.size() - condition.find(' '));
			
			int r_num=0; //无论如何，只要有红球落入，就要计算 
				if(drop.find('r')!=string::npos ){//有红球落入 
					int pos=drop.find('r');
					vector<int> v;
					for(int i=pos+1;i<drop.size() ;i++) {
						if(drop[i]>='0'&&drop[i]<='9') v.push_back(drop[i]-'0'); 
					}
					if(v.size()==1) {
						r_num+=v[0];
						ball[ball_score('r')]-=r_num; 
					}
					else {
						r_num+=v[0]*10 + v[1];
						ball[ball_score('r')]-=r_num; 
					}	
				}
			
			int flag1=1;  //看击打有没有犯规 
			int maxi1=4;
			if(hit=="r"||hit.size()>1){
				flag1=0;
				for(int i=0;i<hit.size();i++){
					if(ball_score(hit[i])>maxi1) maxi1=ball_score(hit[i]);
				}	
			} 
			
			if(flag1==0){ //击球犯规，在击球和落球里面找个最大的给对方加分    击球犯规，落球一定犯规 
				for(int i=0;i<drop.size();i++){
					if(ball_score(drop[i])>maxi1) maxi1=ball_score(drop[i]);
				} 
				A_score+=maxi1;
				A_hit_score=0;
				A_red();
				
			} else{       //击球没犯规，只打了一个彩球 
				if(drop==hit){      //落球也完全一样 ,加分继续打红球 
					B_hit_score+=ball_score(drop[0]);
					B_score+=ball_score(drop[0]); 
					B_red(); 
				}else{              //落球多了些东西犯规，给对方加最大分 （击打和落球中的最大分）
					int maxi3=4; 
					for(int i=0;i<hit.size();i++){
						if(ball_score(hit[i])>maxi3) maxi3=ball_score(hit[i]);
					}
					for(int i=0;i<drop.size();i++){
						if(ball_score(drop[i])>maxi3) maxi3=ball_score(drop[i]);
					} 
					A_score+=maxi3;
					A_hit_score=0;
					A_red(); 
				} 
			}	
		} else{//只打了球，没落入 
			if(condition=="r"||condition.size() >1) {//打到了多个球或者打到了红球   没进 
				int maxi=4;
				for(int i=0;i<condition.size() ;i++){
					if(ball_score(condition[i])>maxi)  maxi=ball_score(condition[i]);
				} 
				A_score+=maxi;
				A_hit_score=0;
				A_red();
			} else{                                  //打到单个彩球 但没进 
				A_hit_score=0;
				A_red();
			} 
		} 
		
	} else {       //顺序彩球  
		string sub="rygcbpB";
		string goal=sub.substr(sub.find(fa)+1,1); 
		char c_goal=sub[sub.find(fa)+1 ]; 
		
		if(condition=="NULL") {                          //打空了,犯规,对方加分，按顺序打 
			A_score+=4; 
			A_hit_score=0;
			A_color(fa); 
		} else if(condition.find(' ')!=string::npos ){   //有打球，有落入		
		
			string hit,drop;
			hit=condition.substr(0,condition.find(' '));
			drop=condition.substr(condition.find(' ')+1,condition.size() - condition.find(' '));
			
			if( hit==goal && hit==drop )   { //目标， 击打，落入都一样  
				B_hit_score+=ball_score(c_goal);
				B_score+=ball_score(c_goal);//分数增加 
				ball[ball_score(c_goal)]--; //球数减少 
				B_color(c_goal);            //继续按照顺序击打 
			} else  {  //击球犯规，在所有球里面找最大的
//			if(hit==goal && hit!=drop){
//				int maxi=4;
//				for(int i=0;i<drop.size();i++){
//					if(ball_score(drop[i])>maxi) maxi=ball_score(drop[i]);
//				}
//				A_score+=maxi;
//				A_color(fa);
//			}else if(hit!=goal){	 
				int maxi=max(4,ball_score(c_goal));
				for(int i=0;i<hit.size();i++){
					if(ball_score(hit[i])>maxi) maxi=ball_score(hit[i]);
				}
				for(int i=0;i<drop.size();i++){
					if(ball_score(drop[i])>maxi) maxi=ball_score(drop[i]);
				}
				A_score+=maxi;
				A_hit_score=0;
				A_color(fa);
			}
		}else {                                           //有打球，没落入 
			string hit=condition;
			if(hit==goal){
				A_hit_score=0;
				A_color(fa);
			}else {
				int maxi=4;
				for(int i=0;i<hit.size();i++){
					if(ball_score(hit[i])>maxi) maxi=ball_score(hit[i]);
				}
				A_score+=maxi;
				A_hit_score=0;
				A_color(fa);
			}	
		}
	}
 	
 } 
 
 int main(){
 	int t;
 	cin>>t;
 	cin.get();  //吸收回车 
 	while(t--){
 		A_score=0;B_score=0;  //每局开始，双方分数清零 
 		A_hit_score=0;B_hit_score=0; //击打得分清零 
 		init_ball_num(); //球数初始化 
		A_red();
	 }
	 cout<<A_100_times<<":"<<B_100_times;
 }
 
 
 
 