# Test strings
var str = "hello"
println(find("el",str)) #1
println(str.find("el")) #1

println(substr(0,4,str))
println(str.substr(1,5))

println(str.replace("l","h"))
println(str.replace_once("l","h"))

println(str)
println(str.reverse())
println(str)
println(str.erase(2,3))
println(str)

println(str.insert(4,"world"))
println(str)