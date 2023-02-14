let name = "listcapture"
let age = 18;
let input = document.querySelector(".input")
let run = document.querySelector("button")
let output = document.querySelector("pre");
function mirror() {
    run.addEventListener('click', function () {      
  let x = parseInt(input.value);
    let a = x % 10;
    x = parseInt(x / 10);
    let b = x % 10;
    x = parseInt(x / 10);
    let c = x % 10;
    let s = `${a}${b}${c}`;
    output.innerHTML=s;
    })
}
function print() {
  

}



export {
    mirror,
    print,



}


