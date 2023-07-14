int findCelebrity(int n) {
 	stack<int>st;
	 for(int i=0;i<n;i++){
		 st.push(i);
	 }
	 while(st.size()>1){
		 int id1=st.top();
		 st.pop();
		 int id2=st.top();
		 st.pop();
		 if(knows(id1,id2)){
			 st.push(id2);
		 }else st.push(id1);
	 }
	 int id=st.top();
	 st.pop();
	 for(int i=0;i<n;i++){
		 if(i!=id and (knows(id,i) or !knows(i,id)))return -1;
	 }
	 return id;
}