const fs=require("fs");
const input=fs.readFileSync(0).toString().trim().split('\n');

const n=Number(input.shift());
const list=input.map(Number);

const dp=Array(n).fill(0);
if(n==1) {
  console.log(list[0]);
  return;
}
if(n==2){
  console.log(list[0]+list[1]);
  return;
}
dp[0]=list[0];
dp[1]=list[0]+list[1];
dp[2]=Math.max(dp[0], list[1])+list[2];

for(let i=3; i<n; i++){
  dp[i]=Math.max(dp[i-3]+list[i-1], dp[i-2])+list[i];
}

console.log(dp[n-1]);