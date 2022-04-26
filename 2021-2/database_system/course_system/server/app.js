const express = require('express');
const db = require('./config/db');
const app = express();
const port = 3000;


app.unsubscribe(express.json());

app.listen(port, ()=>{
    console.log(`Example app listening on port ${port}`);
});

app.get('/colleges',(req, res)=>{
    db.query('select * from colleges', (err, rows, fields) => {
        if(err) throw err;
        return res.send(rows);
    })
})

