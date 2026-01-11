let queue = []
let queueThresholdValue = 5

function processRequest(){
    if(queue.length < 0)
        return false

    let elem = queue[0]
    queue.shift()
    return true
}

function pushRequest(req){
    if(queue.length >= queueThresholdValue){
        return false
    }

    queue.push(req)
    return true
}

setInterval(()=>{
    console.log(pushRequest(Math.random()+3) == true ? "Request Going To Be Processed" : "Rate Limited 429")
},2000)

setInterval(()=>{
    console.log(processRequest() == true ? "Request Processed" : "Server is IDLE")
},5000)