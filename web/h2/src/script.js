var cookies = 0;

var jsonData;

fetchJson();

function addCookie() {
    cookies++;
    document.getElementById('cookies-label').innerHTML = "Cookies: " + cookies;
}

function fetchJson() {
    fetch("./data.json")
    .then((res) => {
        return res.json();
    }).then((data) => jsonData = data);
}

function upgradeClick() {
    
}