// Code generated by hero.
// source: C:\Users\David Yap\Desktop\go\src\Tokomedia_2.0\mailing\template\cartCheckout.html
// DO NOT EDIT!
package template

import (
	"bytes"

	"github.com/shiyanhui/hero"
)

//CartCheckoutTemplate C
func CartCheckoutTemplate(name string, date string, items []string, buffer *bytes.Buffer) {
	buffer.WriteString(`

<!DOCTYPE html>
<html lang="en">
    <head>
        <title> Cart Checkout </title>
        <meta charset="UTF-8">
        <style>

        </style>
    </head>
    <body>
        <h3> Tokomedia Cart Checkout </h3>
        <p> Orderan Anda Telah dibuat dengan data data sebagai berikut</p>
        <ul>
            <li>Nama Pelanggan  : `)
	hero.EscapeHTML(name, buffer)
	buffer.WriteString(`</li>
            <li>Waktu Pemesanan : `)
	hero.EscapeHTML(date, buffer)
	buffer.WriteString(`</li>
            <li>Item            :
                <ul>
                    `)
	for _, val := range items {
		buffer.WriteString(`
                        <li> `)
		hero.EscapeHTML(val, buffer)
		buffer.WriteString(`</li>
                    `)
	}
	buffer.WriteString(`
                </ul>
            </li>
        </ul>
    </body>
</html>`)

}
