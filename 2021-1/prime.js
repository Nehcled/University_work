function gcd(a,b){
    let mod = a;
    let n,c,t1 = 0,t2 = 1,t;
    while(b){
        n = Math.floor(a/b);

        c = a%b;
        a = b;
        b = c;

        t = t1-t2*n;
        t1 = t2;
        t2 = t;
    }
    if(t1<0)t1+=mod;    
    return [a,t1];
}

let arr = 0;
let prime = [53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199]

let result = {};
let binary = {};


for(let i = 0; i < prime.length; i++){
    result[prime[i]] = [];
    for(let j = 1; j < prime[i]; j++){
        let res = gcd(prime[i],j)
        if(res[0]===1){
            if(binary[res[1]]===undefined){
                binary[res[1]] = res[1].toString(2);
            }
            result[prime[i]].push(res[1]);
        }
    }
    result[prime[i]] = result[prime[i]].sort((a,b)=>a-b).join(", ");
}

console.log(binary);


