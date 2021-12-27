const list = window.JSON.parse(localStorage.getItem("list") || '[]')
function $(queryDom) {
    return document.querySelector(queryDom)
}
function render() {
    const div = document.createElement('div')
    const h1 = document.createElement('h1')
    list.map((item, index) => {
        const span1 = document.createElement('span')
        const span2 = document.createElement('span')
        const spanSplit = document.createElement('span')
        const br = document.createElement('br')
        span1.innerHTML = item.name
        span2.innerHTML = item.pass
        span1.className = 'copyItem'
        span2.className = 'copyItem'
        spanSplit.innerHTML = ':    '
        span1.addEventListener('click', copy)
        span2.addEventListener('click', copy)
        h1.appendChild(span1)
        h1.appendChild(spanSplit)
        h1.appendChild(span2)
        h1.appendChild(br)
    })
    div.appendChild(h1)
    $('#container').appendChild(div)
}
function copy(e) {
    e.preventDefault();
    const input = document.createElement('input');
    input.setAttribute('value', e.target.innerHTML);
    document.body.appendChild(input);
    input.select();
    document.execCommand('copy')
    document.body.removeChild(input);
};
$('button').addEventListener('click', () => {
    const name = prompt('name')
    const pass = prompt('password')
    list.push({
        name,
        pass
    })
    $('#container').childNodes.forEach((_, index) => {
        $('#container').removeChild($('#container').childNodes[index])
    });
    console.log($('#container').childNodes);
    localStorage.setItem("list", JSON.stringify(list))
    render()
})
render()