#include <stdio.h>
void main(){
int a[50],b[50],c[100],i,m,n,j,k;
printf("Enter the size of the first array :\n");
scanf("%d",&m);
printf("Enter the elements of the first array(sorted order) :\n");
for(i=0;i<m;i++){
scanf("%d",&a[i]);
}
printf("Enter the limit of the second array:\n");
scanf("%d",&n);
printf("Enter the elements of the second array(sorted order):\n");
for(j=0;j<n;j++){
scanf("%d",&b[j]);
}
i=0;j=0;k=0;
while(i<m && j<n){
if(a[i]<b[j]){
c[k]=a[i];
k++;
i++;
}
else
{
c[k]=b[j];
}}
while (i<m){
c[k]=a[i];
i++;
k++;

}
while(j<n){
c[k]=b[j];
k++;
j++;}
printf("\nMerged array is:");
for(i=0;i<m+n;i++){
printf("%d",c[i]);
}
printf("\n");

}

