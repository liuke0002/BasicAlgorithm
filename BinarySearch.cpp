int bin_search(int str[],int n,int key){
	int low,high,mid;
	low=0;
	high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		if(str[mid]==key){
			return mid;
		}
		if(str[mid]<key){
			low=mid+1;
		}
		if(str[mid]>key){
			high=mid-1;
		}
	}
	return  -1;
}
