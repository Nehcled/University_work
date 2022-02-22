const fs = require("fs");
const path = require("path");
// let dictionary = JSON.parse(fs.readFileSync(`./7kwords.json`, 'utf-8'));


const numToWord = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'];
const wordToNum = { 'A': 0, 'B': 1, 'C': 2, 'D': 3, 'E': 4, 'F': 5, 'G': 6, 'H': 7, 'I': 8, 'J': 9, 'K': 10, 'L': 11, 'M': 12, 'N': 13, 'O': 14, 'P': 15, 'Q': 16, 'R': 17, 'S': 18, 'T': 19, 'U': 20, 'V': 21, 'W': 22, 'X': 23, 'Y': 24, 'Z': 25 };
const multiplyInverse = [1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25];


function gcd(r1, r2) {
    let q = 0, r = 0, s1 = 1, s2 = 0, s = 0, t1 = 0, t2 = 1, t = 0;
    while (r2) {
        q = Math.floor(r1 / r2);
        r = r1 % r2;
        r1 = r2;
        r2 = r;

        s = s1 - s2 * q;
        s1 = s2;
        s2 = s;

        t = t1 - t2 * q;
        t1 = t2;
        t2 = t;
    }
    let result = new Array(3);
    result[0] = r1, result[1] = s1, result[2] = t1;
    return result;
}

async function sleep(ms) {
    return new Promise(r => setTimeout(r, ms));
}

function mod(num, modnum) {
    return num < 0 ? num % modnum + modnum : num % modnum;
}


function plus(crypto,key){
    let result = new Array(crypto.length);
    for(let i = 0; i < crypto.length; i++){
        result[i] = numToWord[mod(wordToNum[crypto[i]] + key,26)]
    }
    return result.join("");
}


//#####################################################################################################

function multiply(crypto, key) {
    let result = new Array(crypto.length);
    for (let i = 0; i < crypto.length; i++) {
        result[i] = numToWord[mod(wordToNum[crypto[i]] * key, 26)];
    }
    return result.join("");
}
function unMultiply(crypto, key) {
    let result = new Array(crypto.length);
    let inverseKey = mod(gcd(26, key)[2], 26);
    for (let i = 0; i < crypto.length; i++) {
        result[i] = numToWord[mod(wordToNum[crypto[i]] * inverseKey, 26)];
    }
    return result.join("");

}

//#####################################################################################################

function affine(crypto,mkey, pkey) {
    if(!crypto){
        return "";
    }
    let result = new Array(crypto.length);
    for (let i = 0; i < crypto.length; i++) {
        result[i] = numToWord[mod(wordToNum[crypto[i]] * mkey + pkey, 26)];
    }
    return result.join("");
}
function unAffine(crypto,mkey,pkey) {
    let result = new Array(crypto.length);
    let inverseKey = mod(gcd(26, mkey)[2], 26);

    for (let i = 0; i < crypto.length; i++) {
        result[i] = numToWord[mod((wordToNum[crypto[i]] - pkey) * inverseKey, 26)];
    }
    return result.join("");
}

//#####################################################################################################

function autoKey(crypto, key) {
    if(!crypto){
        return "";
    }
    let result = new Array(crypto.length);
    for (let i = 0; i < crypto.length; i++) {
        result[i] = numToWord[mod(wordToNum[crypto[i]] + key, 26)];
        key = wordToNum[crypto[i]];
    }
    return result.join("");
}

function unAutoKey(crypto, key) {
    let result = new Array(crypto.length);
    for (let i = 0; i < crypto.length; i++) {
        key = mod(wordToNum[crypto[i]] - key, 26);
        result[i] = numToWord[key];
    }
    return result.join("");
}

//#####################################################################################################

function vigenere(crypto, key) {
    let result = new Array(crypto.length);
    for (let i = 0; i < crypto.length; i++) {
        let word = wordToNum[crypto[i]] + wordToNum[key[mod(i, key.length)]];
        result[i] = numToWord[mod(word, 26)];
    }
    return result.join("");
}

function unVigenere(crypto, key) {
    let result = new Array(crypto.length);
    for (let i = 0; i < crypto.length; i++) {
        let word = numToWord[mod(wordToNum[crypto[i]] - wordToNum[key[mod(i, key.length)]], 26)];
        result[i] = word;
    }
    return result.join("");
}

//#####################################################################################################

function playfair(crypto, key) {
    let r0 = "";
    for (let i = 0; i < crypto.length - 1; i++) {
        if (crypto[i] === "J") r0 += "I";
        else r0 += crypto[i];
        if (crypto[i] === crypto[i + 1]) r0 += "X";
    }
    r0 += crypto[crypto.length - 1];
    if (r0.length % 2) r0 += "X";
    let keyTable = {};
    for (let i = 0; i < 5; i++) {
        for (let j = 0; j < 5; j++) {
            keyTable[key[i][j]] = {};
            keyTable[key[i][j]].row = i;
            keyTable[key[i][j]].col = j;
        }
    }
    let result = new Array(r0.length);
    for (let i = 0; i < r0.length; i += 2) {
        if (keyTable[r0[i]].row === keyTable[r0[i + 1]].row) {
            result[i] = key[keyTable[r0[i]].row][mod(keyTable[r0[i]].col + 1, 5)];
            result[i + 1] = key[keyTable[r0[i + 1]].row][mod(keyTable[r0[i + 1]].col + 1, 5)];
        } else if (keyTable[r0[i]].col === keyTable[r0[i + 1]].col) {
            result[i] = key[mod(keyTable[r0[i]].row + 1, 5)][keyTable[r0[i]].col];
            result[i + 1] = key[mod(keyTable[r0[i + 1]].row + 1, 5)][keyTable[r0[i + 1]].col];
        } else {
            result[i] = key[keyTable[r0[i]].row][keyTable[r0[i + 1]].col];
            result[i + 1] = key[keyTable[r0[i + 1]].row][keyTable[r0[i]].col];
        }
    }
    return result.join("");
}
//#####################################################################################################
function explosionPlus(length){
    let result = [];
        let start = dictionary.findIndex((word) => word.length === length);
        for (let i = start; dictionary[i].length === length; i++) {
            for (let key = 0; key < 26; key++) {
                result.push([dictionary[i],key,plus(dictionary[i],key)]);
            }
        }
    return result;
}

function explosionMultiply(length, target = "") {
    let result = [];
    if (!target) {
        let start = dictionary.findIndex((word) => word.length === length);
        for (let i = start; dictionary[i].length === length; i++) {
            for (let key = 0; key < 12; key++) {
                result.push([dictionary[i],multiplyInverse[key],multiply(dictionary[i],multiplyInverse[key])]);
            }
        }
    }
    return result;
}

function explosionAffine(crypto){
    let cryptolen = crypto.length
    let matchSet = [];
    let start = dictionary.findIndex((word)=>word.length===cryptolen);
    console.log(crypto);
    for(let runWord = start; runWord<dictionary.length; runWord++){
        for(let i = 0; i < 26; i++){
            for(let j = 0; j < 12; j++){
                let secret = affine(dictionary[runWord],multiplyInverse[j],i)
                if(secret.startsWith(crypto)){
                    matchSet.push([crypto,dictionary[runWord],multiplyInverse[j],i]);
                }
            }
        }
    }
    return matchSet;
}
function explosionAutoKey(crypto){
    let cryptolen = crypto.length
    let matchSet = [];
    let start = dictionary.findIndex((word)=>word.length===cryptolen);
    console.log(crypto);
    for(let runWord = start; runWord<dictionary.length; runWord++){
        for(let i = 0; i < 26; i++){
            let secret = autoKey(dictionary[runWord],i);
            if(secret.startsWith(crypto)){
                matchSet.push([dictionary[runWord],i]);
            }
        }
    }
    return matchSet;
}
//#####################################################################################################
function explosionVigenere(crypto) {
    let cryptolen = crypto.length;
    let start = dictionary.findIndex((word) => word.length === cryptolen);
    let matchSet = [];

    for (let ansWordIndex = start; dictionary[ansWordIndex].length <= cryptolen; ansWordIndex++) {
        for (let keyIndex = 0; dictionary[keyIndex].length <= cryptolen; keyIndex++) {
            let secret = vigenere(dictionary[keyIndex], dictionary[ansWordIndex]);
            if (secret === crypto) {
                matchSet.push([dictionary[keyIndex], dictionary[ansWordIndex]]);
            }
        }
    }

    return matchSet;
}



// let length = 6;
// let fpath = path.join(__dirname,`matchData${length}.json`);


// let multiplySet = explosionMultiply(length);     
// console.log(multiplySet.length);
// console.log("multiplySet collect finished");
// let matchSet = {};
// for(let i = 0; i < 1500&&i<multiplySet.length; i++){
//     console.log("explotion index:",i);
//     if(!multiplySet[i])continue;
//     let result = explosionVigenere(multiplySet[i][0]);
//     if(result.length){
//         matchSet[`${multiplySet[i][2]},${multiplySet[i][3]},${multiplySet[i][1]},${multiplySet[i][0]}`] = result;
//     }
// }
// fs.writeFileSync(fpath, JSON.stringify(matchSet, null, 2));


// let matrix = [["L", "G", "D", "B", "A"],["Q", "M", "H", "E", "C"],["U", "R", "N", "I", "F"],["X", "V", "S", "O", "K"],["Z", "Y", "W", "T", "P"]];
// let secret = affine("CORNEREDINTHE",15,23);
// let secret2 = unMultiply(secret,11);
// let matrix = [["F","U","E","H","V"],["B","N","K","M","Q"],["Z","L","Y","C","P"],["W","O","R","T","D"],["I","G","A","S","X"]];
// let secret = playfair("WHEREDOYOUGATI",matrix);
// console.log(secret);

// console.log(unAutoKey(secret,5));
for(let i = 1 ;i<26; i+=2){
    if(i === 13)continue;
    console.log(gcd(26, i)[2]);
}
// console.log(unAffine("BZSKFSFQNKWYF",15,23));
// console.log(unVigenere("KJIIRGVFU","IVORY"));
// stream.close();

// const target = JSON.parse(fs.readFileSync(`./matchData14.json`, 'utf-8'));
// let multiplySet = explosionPlus(5);  
// let set = {};
// for(let i = 0; i < multiplySet.length; i++){
//     // let affineSet = explosionAffine(target[i]);
//     let autoKeySet = explosionAutoKey(multiplySet[i][2]);
//     if(autoKeySet.length){
//         set[multiplySet[i][0]+"-"+multiplySet[i][1]] = autoKeySet;
//     }
//     // console.log(affineSet,"done");
//     // console.log(autoKeySet,"done");
// }
// fs.writeFileSync("./matchData13.json",JSON.stringify(set,null,2));