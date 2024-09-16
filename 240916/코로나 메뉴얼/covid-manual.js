// 입력 및 변수 선언
const fs = require("fs");
let input = fs.readFileSync(0).toString().trim().split("\n");

let personA = input[0].split(" ");
let personB = input[1].split(" ");
let personC = input[2].split(" ");

let symptomA = personA[0], temperatureA = Number(personA[1]);
let symptomB = personB[0], temperatureB = Number(personB[1]);
let symptomC = personB[0], temperatureC = Number(personC[1]);

// A가 2명 이상인지 판단하기
if (symptomA === "Y" && temperatureA >= 37) {
    // 첫 번째 사람이 A라면, 남은 두 사람 중 한 사람이라도 A면 됩니다.
    if ((symptomB === "Y" && temperatureB >= 37) || (symptomC === "Y" && temperatureC >= 37)) {
        console.log("E");
    }
    else {
        console.log("N");
    }
}
else {
    // 첫 번째 사람이 A가 아니라면, 남은 두 사람 모두 A여야만 합니다.
    if ((symptomB === "Y" && temperatureB >= 37) && (symptomC === "Y" && temperatureC >= 37)) {
        console.log("E");
    }
    else {
        console.log("N");
    }
}