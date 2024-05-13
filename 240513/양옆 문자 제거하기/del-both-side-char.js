const fs=require("fs");
let input=fs.readFileSync(0).toString();
let size=input.length;
let answer=input.slice(0,1)+input.slice(2,size-2)+input.slice(size-1);
// console.log(input.slice(0,1));
// console.log(input.slice(2,size-2));
// console.log(input.slice(size-1));
console.log(answer);