package main

import (
	"bytes"
	"myapp/service"
	"myapp/template"
	"os"
	"strconv"
)

func main() {

	sender := os.Args[1]
	pass := os.Args[2]
	subject := os.Args[3]
	mailType := os.Args[4]
	paramCount, _ := strconv.Atoi(os.Args[5])
	paramArr := os.Args[6:(6 + paramCount)]
	receiver := os.Args[(6 + paramCount):]

	var bufferTemplate bytes.Buffer

	if mailType == "1" {
		template.CartCheckoutTemplate(paramArr[0], paramArr[1], paramArr[2:], &bufferTemplate)
	}

	service.SendEmail(sender, pass, receiver, subject, bufferTemplate.String())

}
