let test = (basic,pow, mod) => {
    let arr = [];
    // let pow = mod-1
    console.log(pow.toString(2));
    while(pow){
        arr.push(pow&1);
        pow>>=1;
    }
    let y = 1;
    for(let i = 0; i < arr.length; i++){
        if(arr[i]){
            y=y*basic%mod;
        }   
        basic = basic*basic%mod;
        console.log(arr[i],y,basic);
    }
    return y;
}

console.log(test(36191,10423,36863));

