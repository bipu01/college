# make a program that sends a get request to a google.com and consoles the output
import requests


def fetch_google_homepage():
    response = requests.get('https://www.google.com')
    print(response.text)


if __name__ == "__main__":
    fetch_google_homepage()
