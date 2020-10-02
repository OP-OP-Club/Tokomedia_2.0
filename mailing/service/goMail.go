package service

import (
	"log"

	gomail "gopkg.in/gomail.v2"
)

//SendEmail Send Email
func SendEmail(sender string, password string, recipients []string, subject string, htmlBody string) {

	configEmail := sender
	configPassword := password

	m := gomail.NewMessage()
	m.SetHeader("From", configEmail)

	addresses := make([]string, len(recipients))
	for i, recipient := range recipients {
		addresses[i] = m.FormatAddress(recipient, "")
	}

	m.SetHeader("To", addresses...)
	m.SetHeader("Subject", subject)
	m.SetBody("text/html", htmlBody)

	d := gomail.NewPlainDialer("smtp.gmail.com", 587, configEmail, configPassword)
	if err := d.DialAndSend(m); err != nil {
		panic(err)
	}

	log.Println("Mail sent!")
}
