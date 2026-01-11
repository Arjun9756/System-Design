let m1 = new Map() // treat this as a redis
let thresholdValue = 3

function resetMapValue(){
    m1.clear()
}

function processRequest(deviceIPAddress){
    let value = m1.get(deviceIPAddress) || 0
    if(value >= thresholdValue){
        console.log("Rate Limited 429")
        return false
    }

    m1.set(deviceIPAddress , value+1)
    console.log("Allowed:", deviceIPAddress, value + 1)
    return true
}

setInterval(()=>{
    resetMapValue()
},5000)

setInterval(()=>{
    let deviceIPAddress = "191.162.0.1"
    processRequest(deviceIPAddress)
},1000)