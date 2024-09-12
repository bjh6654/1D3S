function convertTo10(num, d) {
    const arr = num.split('');
    
    let sum = 0
    for (let i = 0; i < arr.length; i++) {
        sum += Math.pow(d, arr.length-i-1) * arr[i];
    }
    
    return sum;
}

function solution(expressions) {
    var answer = [];
    
    let mini = 2;
    let fixed = -1;
    expressions.forEach(e => {
        const sp = e.split(" ");
        const n1 = sp[0], n2 = sp[2], op = sp[1], r = sp[4];
        mini = [...n1.split(''), ...n2.split(''), ...r.split('')].reduce((pre, cur) => {
            if (cur != 'X' && parseInt(cur) <= 9) {
                return Math.max(pre, parseInt(cur)+1)
            } else {
                return pre;
            }
        }, mini);
    });
    
    let avail = [];
    for (let i = mini; i <= 9; i++) {
        avail.push(i);
    }

    expressions.forEach(e => {
        const sp = e.split(" ");
        const n1 = sp[0], n2 = sp[2], op = sp[1], r = sp[4];

        if (r != "X") {
            avail = avail.filter(e => {
                if (op == '+') {
                    if (convertTo10(n1, e) + convertTo10(n2, e) != convertTo10(r, e)) return false;
                } else {
                    if (convertTo10(n1, e) - convertTo10(n2, e) != convertTo10(r, e)) return false;
                }
                return true;
            })
        }
    });
    
    expressions.forEach(e => {
        const sp = e.split(" ");
        const n1 = sp[0], n2 = sp[2], op = sp[1], r = sp[4];
        
        if (r == "X") {
            const a = avail.reduce((pre, cur) => {
                if (op == '+') {
                    return [...pre, (convertTo10(n1, cur) + convertTo10(n2, cur)).toString(cur)];
                } else {
                    return [...pre, (convertTo10(n1, cur) - convertTo10(n2, cur)).toString(cur)];
                }
            }, []);

            // console.log(e, avail, a);
            
            if ( [...new Set(a)].length == 1 ) {
                answer.push(`${n1} ${op} ${n2} = ${a[0]}`);
            } else {
                answer.push(`${n1} ${op} ${n2} = ?`);
            }            
        }
        

    })

    return answer;
}

// 2024-09-11