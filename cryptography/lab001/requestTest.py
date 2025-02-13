import requests


def make_api_call(search_term):
    url = 'https://www.google.com/search'
    params = {'q': search_term}

    response = requests.get(url, params=params)

    if response.status_code == 200:
        print('API call successful')
        # Process the response data here
    else:
        print('API call failed')


# Example usage

if __name__ == "__main__":
    search_term = input("Enter what you want to search in GOOGLE: ")
    make_api_call(search_term)
