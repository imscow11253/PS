const fs=require("fs");
const input=fs.readFileSync(0).toString().trim().split('\n');

const [n,m,k,x]=input.shift().split(' ').map(Number);

const link=Array.from(Array(n+1), ()=>[]);
for(let i=0; i<m; i++){
  const [from, to]=input[i].split(' ').map(Number);
  link[from].push(to);
}

const queue=[[x, 0]];
const visited=new Set();
visited.add(x);
const answer=[];
let index=0;
while(queue.length>index){
  const [curr, cnt]=queue[index++];
  
  if(cnt>=k){
    if(cnt==k) answer.push(curr);
  }
  for(const next of link[curr]){
    if(!visited.has(next)){
      visited.add(next);
      if(cnt+1>=k){
        if(cnt+1==k) answer.push(next);
      }
      else queue.push([next, cnt+1]);
    }
  }
}

console.log(answer.length==0? -1: answer.sort((a,b)=>a-b).join('\n'));