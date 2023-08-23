from flask import *
from datetime import datetime
from pytz import timezone


app = Flask (__name__)

# Display current time in New york
@app.route("/")
def time():
    now = datetime.now(timezone ('America/New_York'))
    return "The current date and time in New York is {}".format(now)


# url/show/ANY_NUMBER
@app.route("/show/<number>")
def show(number):
    return "You passed in {}".format(number)