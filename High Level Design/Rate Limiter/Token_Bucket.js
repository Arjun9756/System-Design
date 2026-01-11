let fillingRate = 5
let bucketSize = fillingRate

function processClientReq(){
    if(bucketSize <= 0)
        return false
    bucketSize--
    return true
}

function refillMyBucket(){
    bucketSize = fillingRate
}

setInterval(()=>{
    refillMyBucket()
},5000)

setInterval(()=>{
    console.log(processClientReq() === true ? "Request Processed" : "Too Many Request 429")
},2000)