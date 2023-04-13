const app = require('express')()
const bodyParser = require('body-parser')
app.use(bodyParser.urlencoded({extended:true}))
const port = 8000

app.post('/test', (req, res) => {
    console.log('post request received')
    console.log(req.body)
    res.sendStatus(200)
})

app.listen(port, () => {
    console.log('app running at port: ' + port)
})