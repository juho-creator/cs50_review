from cs50 import SQL
from flask import Flask,request, redirect, render_template

app = Flask(__name__)
db = SQL("sqlite:///database.db")

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/signup', methods = ["POST"])
def signup():
    username = request.form.get('username')
    password = request.form.get('password')

    if not username or not password:
        return render_template('failure.html')
    
    db.execute("INSERT INTO credentials (username, password) VALUES (?, ?)", username, password)
    return render_template("success.html", USERNAME = username)

@app.route('/users')
def users(): 
    USERS = db.execute("SELECT * FROM credentials")
    return render_template('user.html', users=USERS)



@app.route('/deregister',methods = ["POST"])
def deregister(): 
    id = request.form.get('id')
    db.execute("DELETE FROM credentials WHERE id = ?", id)
    return redirect('/users')

