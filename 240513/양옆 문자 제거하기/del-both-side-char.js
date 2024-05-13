const fs=require("fs");
let input=fs.readFileSync(0).toString();
let size=input.length;
input = input.slice(0,1)+input.slice(2,)
let answer=input.slice(0,size-3)+input.slice(size-2,);
// console.log(input.slice(0,1));
// console.log(input.slice(2,size-2));
// console.log(input.slice(size-1));
console.log(answer);
// 변수 선언 및 입력
const fs = require("fs");
let input = fs.readFileSync(0).toString().trim();

// 문자열의 길이를 구합니다.
let leng = input.length;

// 앞에서 2번째 원소를 제거합니다. (이때 문자열의 길이가 1 감소하는것을 반드시 기억합니다)
input = input.slice(0, 1) + input.slice(2);
leng -= 1;

// 뒤에서 2번째 원소를 제거합니다.
input = input.slice(0, leng - 2) + input.slice(leng - 1);

// 앞에서 2번째, 뒤에서 2번째 원소가 제거된 문자열을 출력합니다.
console.log(input);