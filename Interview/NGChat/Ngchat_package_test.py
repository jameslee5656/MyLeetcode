# https://docs.google.com/document/d/1iSCBjVV3HOwgwifkCWXMsi9w7AE0KNxWuuURfvR-A-s/edit
# https://pypi.org/project/ngchat-speech-sdk/
# https://pypi.org/project/ngchat-speech-sdk/
# https://pypi.org/project/ngchat-speech-sdk/

import ngchat_speech.speech as speechsdk
with open("wordlist/usernames.txt",encoding = "ISO-8859-1") as fusers:
	userlines = fusers.read().splitlines()

passlines = []
for x in range(1,5):
	with open("wordlist/pw list " + str(x) +".txt",encoding = "ISO-8859-1") as fusers:
		passlines.extend(fusers.read().splitlines())

for user in userlines:
	for password in passlines:
		speech_config = speechsdk.SpeechConfig(account_id=user,password=password)
		audio_config = speechsdk.audio.AudioConfig(filename="test.wav")
		speech_recognizer = speechsdk.SpeechRecognizer(
		    speech_config=speech_config,
		    audio_config=audio_config
		)
		print(user, password)
		break
	break



for user in userlines[:5]:
	for password in passlines[:10]:
		print(user, password)
