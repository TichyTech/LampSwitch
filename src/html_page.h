const char* offPage = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>WiFi Lamp</title>
  <link rel="icon" href="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAIAAAACACAYAAADDPmHLAAAY+0lEQVR42u1dCXhUVZYOrW339LQ9n35uQ2MMoVJvrUAIkKr3qiqVvRJRFkV22UGUTXawEVni2jraLq0ztOO0tk5r2y5tj9iOiuIyitq2+9YKIqgo2IoQFvHO+d9SdauSAGpeLcm933e/qlQqleSec8/5z3/OPbegQIzDGrIvVKkpxkZNi7zv9w/oLVakCw1Jqhij6+Eduh5lgUAlUxXzYXr5CLEyXWAoSmgO7fq9gUCU6XqEQQlUxdhSVBT7sVidzm72ZWMeCf1rCN0VPj0ekOXQYvp2N7FCnXhoijmZhL3fFnyEwQKQJWjxy6EZYnU6u9kvqagjYe90d75t/o1dilIxQqxOpzf7fYo0PfJe0udHmKZE9wAIitXp9CN2pKwa9wHpu8Kn+Y0mzH7XGKoanaZzOx+KoKnmtWJlusDoXlxeSH5/K+/3NdV41ufz/UysThcYumreyJt+TY18pSh9g2JlusDwqf3KSOhf8aZfUoxLxcp0Gd9v3Jbc/Yj3jfd7nWicIFamC4xevQxdVRHzc4SPQP1dZyhK+OqU3a8a7xYWFh4jVqYLjB49tGMJ7G3mkb8iGQvb/4nyH4IoIkYw6FeDjbIcHqlL5iRNNqaoyBjK4YH4Xg9/75+L1c2L3R8ZkUz0RJiqhrdrWnmh+/2ioqIfU2g4gOoAziVccIemRF7WNPMjep+VHYTlSJ1RfMZeS6kUY52mhJbJ8oAQFEesdu6Nbqoauss1/3ikHX0jvkHZPoNcw2Uk+JdJ6Htc4dr0cJRnCduc7nttIim8j6jlp1U5Os13UuR4sew5Mkp9FT3sIg8n7tfCBxAN0A5/DEJzhc4LVpNNpvoMe5YY1tfWVJxHv2m9rhYb1vN0hSCw+Q6yiZIkHS0kkOURkEOj0ndzcpc7r6kRW6AkcDLrrF9DPYtNHcKaVo5hZ948jY3+02w2ft18NnH9QjbukXls1D2z2JBfT2Z1i0aw4JC4/fP4WcVM+/zwM35/qEZIwYNxilL+rwBiVMkzhHb0LJq/JDN+C5nzB8jnP07C+D9VM17U1fDH7ZlwayeT4AJ9KllkzOns9CsnWAI+59VlbNaHq9mcTy5msz9qtudWbuLrjzEvZue+vZyd/dBcVr9kBOsTillWAQrB1xaoqtl84oml/yyk9h2HpmlHyXJFuaYFx1H4dhMJeQMAWNJvJ8FZ+mzLl1tmnYRfMTDOTvvleDbhyYVsxsaVtsBJwLO2rGYzN69iMz849ISiuAoy6dnFrGHZKNa7T9T6HW7I6eQb1mrFSeApxiFGcXH5vyAEQ/yuK+bfQOGmC/pQIK1N4FYaZdFxg9iI/z6PTX9zubWLZ209fIEfVBm2kPKQIpz98FxmjhhoWZekNSCgqJmv+pRgXyHd9scRkhQ0qUbvGhA17sK1JWyFFrZEibBiyZ54LtFrsmp/T1PbUAB6T1moik16bjE7/9NLrN37fYXe1oRFgGsAhqA0M4cNqNJYC2/y+8vDQtTcKCwMHEOh2kRVM9cTSt/bltAhWAjap9jPI32jbHSkks2Px9gVQ6vZrWNr2ANTatnjM+rY83Ma2Ovz69nK06tYsdLa/NfMGcZmbiJhfbjKEwWwrcFqyy0M+6/prHd5pRU9JC1BeIvNG3TxQfz8CYpkLtCU8FttmXXJEToEXj8gyuaSsNeMqmHPzGxgG5fE2WcXNrI9q5vY182nsn3NTWwfPd/rzJZVTWxeY5WlMG1hgMHXTbJ2qlcKYE1yKwCLo++fzcqMqkTIaCtB5H1FMfQuKfhjj/X9TNHDsykOfzdd8DDfxc4uHxSMskuGVLHHz6tjH17QaAl1f3NSwLtpfrWy9dxFr28n5Ti1Imp9joX4dc4tKDYWGHnPTEtAnioBXALhjLFrz7eVQE6GisA2iGa6lPD9SmiwpoefTzfzrokPEYJeRDv3kXPr2CfLGhO7GgLftbJtgadPvPfdRXFW0dvBA/T5/em5+7VL9kAg4x6dnxElmENKMOaBOay0fywFE1BEcy+o6M4fyvXq61Pk8O1g4loJnnZkHZn4a8+qZm8tjFsChODb2+GHmlCYp8lNBAK28CX6/Gk1MXbnhJoUS6D6DVZeXcfGP7EgQ5agmQ2/4zym4+9SOWCoBpd3auFLkjGBkixbWpl62vG1/aLsppHVbPPSuOXHW1Yf/k5vb8JN3DepNuH/8XsACPH51w2vZj7JVgwXD5TXkBI8Nt8y1Z5jAsIdp181geMJIvZBlM7IGBYV9T8J7Fzy0IX9D0Mw/ckHX3lmtQXmILCWVd9P6OkKcDOBxUIHdBWRwP+DlOxren3niia2wokOeCUoM6ssitcChh6Fh9akyAOkU/XMM22ewGUMKQOJaKgTsXf9BtCu/ytfgCk7sfuM+hh7aW59wrd3lOATGIA+97Ih1aynlFS4P06stRQAv+/zi+JscVOVZRk0jhYO9I6yQVdPtASEEM4zV0BKds5ry9iApoaU8LDT1CdSmnUU+frt6bs+SrH778fXsC9X2H66owVvRQA0d9Jc5ISArs9/jEAlXICrIJ8vb2QXDExTAsXO8lVOGszGP77AEpRFC3ckN/CxTRKdddt0Vl5bl1AAi7JWwzsoVe3PZ9l3U3Rzga6b+13ha44Pnlods8gZmOfdq7wRvqsAX5CC4feVOApQRqDrBSKH9qxOjRTwPpBIAIkKxxzCNJf2i7HGVWPYlBeWJpJA35ouhs/faieO8HzSc0vYkBsms+CguJ2PUMxWHIXf3zeSl5KP0XErqoy5PB3hY2GvIl+PHefVrk9XgM8vamJnhSstIskKAUsj7E0nuuDfu9vhEm4fV0NhYtRSGJ23BpTZK4tUkyKMttLBM95fafH9AIuudeCnnSVMfu/cdy6in1vAhtw4hUUnDk5kC/kagmT6GDSx+T8+X0X+HVChUzU/wtEqXvjYVUFa1HsJje9Z7e2ub0UCkbI1DbBJIJj/UFmUbVoSbxNvQGEQcj43q4ENJ2q5OM0a2IoQopRxlIXOaGTx5aMt8w1iZ8JTC61djYnnSAKNuGsGG3ztJItuho/v3ZcE2zPU5o53STDiRd7AcbXu3ct/ko97/8h04WMnIbx7imJxmPxdHu309hRgG7GAleVRS5CYJinAx79oPKgS7m22f+5Xw6q/rigNH+jpUNB80YhVP1BsWAqBWL5PRcwikzDxHCAS7kOGwH12JZGutp+ZVPXwK+hMks/ov1u62QfwGkgU7ivz7PDOC8HDouxc2TYdjK+3krCRLHIVoJqUAcJtTwHweos1G7850Bzf9uaChv2XEzaI0c/h//FxIWOKQihmymxP2C7ZpaR8P/yNogw4P6/Rvi6b8/mCCyzUUKOSvbkgnkDcHQ7wyL/fMqaGjY1WsquHVbN/UEjHCxbPkTcwOQVAIunTdhQAgsdnXEOfNTocPbBmZPUevI6/f9PiOPvd2bUWoKxwMEJPJ/WcSDvryYnX4PqKnfcBgwTo9Tj9/tkU+kIRJT45FYj8g/ISp+al8NFFg/6JfbzZH0jJF6+E7wpl7dRaVkSmGMoGggcAE4J1ASYEunlpo2X2Fac+AAL4LE0BdjmfB+FfOrjKEpj9mSZ7kH6HS07hEWHr2wQi755Qyy4iEmliVaWVaDLLqH6QAGY5TYN+HxRtJOGI2Q0xdiklsf5A739pbtyySPgsuES8T04tGfuopKR/nzyL81GeFfnUNf0l9A/V9LPN/j4PkT6InDtpUU92ULS760DqvDbftgRfX9xkJZF4BYBgdiAKabaFjvkFCf5Jqh3gw0V8Jj779+Nt0ohXFj4TiSgDmOIDUrSNS+yJ51vJ8kDR3L8V79/DJbLw9V+m1bM+gaQ7sKqIlcgL/vLYcfmRzaM/1Gb4ogn/BvP4pAP4vET4WMhNtNiDQ5UWt+AqAbh9ZPrm0M7DrgPpY5QlXQB8+XtkzpFoWkep5ZtG1rAx0cqE5XKtGD5ziFlp/Y6DMZRu+NjSxtx9iKwlNgjCTllNKp2dEDJuK8iDnoTdVNm42aV3NWeBQbN6LXw+0/cy0cinEdDsybF4+Dt8ju/FDgukhFu2hXKVAq5D4nY9HvFzZ5DwYUm85Ctca3IpUdV8tZJlCUpC03Ib9PmNsTzowz9wJaHljsjgfVslQBJpCVG5mpNV5FG61g4SV9TU77kZSSjMikFVVkYyE2RVi8NVTKmuTGQsHTzwmRwIBXIU9JWdwqd0Ifwp5D/hW1tWZU74/CJC6daTSYfpT0fp6QgdX0uclZCd8HA5gTrQxK4Jz6QSv07WprJvOigMP4gy+FyT/w+obeqtrulXnKLMV+fVZ2THHMyc7nWsD/z7HeRbkeBBiAjgF+xto3Q8QthDzSg7t9YuIn1war0VLcB67cmwBePT1nCfUgoewNGyHHMFiFX5bprYRQAymfL7h+tXXdS9Y3kT+4hQOgQMdI7HLYTQQQahHmC/Ewl8mzIzL6YLGBc0xhJ4wD5EEtmcM0fPjz9e+ynV6D/nmn4IH7voizQCJlfmrnZQ+u7DQOjZmFBYWC9Q1zJ3iESRQ1flRjmXEpnOm36QHi+Sz8ym6e9sExYJ7KYb2lodTJTwF1kHhEhSuDX7bpx8OYUve1fn3k7K59niJLCQwi5ROG5AN36TVQXAqVue8HEJlRax+z2xAn+eXMvlCqw+AzuzdmsJmhtQgcKr/O6/nipq9zULYXkFCFGreHYslmIFKF18XXZ2v2SOdkkfK2YmJg3ki9j93k1srj9PSVoBOyIIfyLLwaIMi3/YEUT6PMrvfmTdxO733gogbT3MtMvZEqeH5ODczJZ0F/fvTwULuy00qtuJFrBWYvdnBgv8lk468xQxyeL5Hj1C/5Q58y+bV7ihHwgKnMrNxRi6s0YEfyegjRJ6JVk9tA/X2WWS+HndNf/wRw9RDluY/8wRWSCHrDMLfEioGVdmCP0b1S7tC/DXRJUvWy7ITsKnK4PBh6fXcdGA1WPo9Yw0mqKmBZclzD+BP5yj2yd8f8bdADZdI9ffgDiBvZIUMb0FfwXaUTzvDw38X9JEoQDZyXIudY6uJbuKGIu8VQBfRFWJgwb6d/PlG5cI858tN3APHarh3YBzla2X1G/wLNf8IwyZUSvQfzazhKiwRmcTLYEDzA969qw40cNq3+A1fPh3A1G/+wX6zxophArjkZGUM4v7Vb8Z8dACmOt5/4/mTCLtm0U3QGv/i9NScQDOEHp1wPN43KFjXaZAvyxEpucdKlTYIxQgy6xgbVrhqHGDNwqghso0ujfXJX+Qm962rDEnq366yoT1XT+jISU5pCvhdR4RQOE4H/+jjYtA/7lRLobCVlRjOXmBNzwhhOg+nKm8AqwaJABgLhBCOKuQJITss4SepIc1JbiKDwF/Q122BP+f/UhgO1U4j45WcpGAsavUi47juh76NR8B3E316oIBzD4jiMfpNcmycTo4Qn0FjGjHK4AavpNXACQjRAiYG4zgPErH9+RCQU96CuBGCz4F/PRMoQC5MHHMfFkaF6D4o8M7XgG4EjAowIbZovY/V7iAlYNSFUD3h8d6YAHMJ3kF+Ov59UIBckQBLsFRck4BJLrFtONpYMV4gleAF8Tpn5xRgObBqRZALjHGe6AA5sO8Ajw7W2CAXFGAi9IwAO4y9oAHMP7ERwFPiERQzijA4qZYmgIEh3pRCvZbXgEemCx4gFw59j6zPsa1k6FkXUlFXccrAB1H5pnA28fVCiYwB5hA9EVEWzo3I4j7jnFjqhdh4CK+GASNE0UuIPu5ALSjQ2cTyc0F6JHPqaG06oELCA7nk0HwO0IBsqwA5ILfsw6JJLOBdD7g/ZN8HlxPj1Ij8MwuBoDZ+XJFXNQDZLkeAHxMSv8guhDbk36CihItoY6Vn7kVwY3UZOmDpXFRE5DlPMB9k1Mrg6kp9d2eFITg8CFxAYl+AGi0+Le5gg3MdgiIU9mpNYFh766Yo4TQfXwzKLQwE5FAlkJAWN4VSAWnNpOkPs1neFgWHlqcfixMAMHsRQBwwXX9ktVARNd/Qfcte3ffsOIP1vJAEK3Pt18oCkOzBQDRzVxO6SpuvurpNbMnn1zWnSqDP7TvsbF76L5M3UBFaXh2/P81Z6X5f9242fvuIFxOAIQQulUIN5CthlHp/t+DJFBrRjA0g6eEp1FH650uKBHCyVg5OG5W7eNcfh2wqoGN7T5feS/vFYBoRgIbX7r9gVCTjv5Awg1k1vzfMKKGM/9Wg4i1JJ5uGekQRg0iH+HdwI0jhBvI9KHQYegaqqb0BpiawQ6hoWmuG0ASAjdpfCqigYwdCMWVN2no/1NJKu2ZMQX4ua+iB06gJCqE6I9ZO7VWWIEM5P+xyeZT+3gf3yBKDf0u451CKRr4dx4MnkOMFHrtCzDoNfiLWx3ZE/cZaZEDsjygIQuNossr7GaRzh9DVmD9jDpBDXtZ/UMKAPaVB390vewznpI/Bxk/kDlOAFeznUctY0RI6B3zh9vQ+pemXh8jyx5UAB82NRwI1ro9AzXnmrhHpgsr4FXt39KU5pAAf+FXqHFHVq+TPyK9WniMyA94gvyfpEYQAT1190tqeGJBtoffHw4TEGnhL4wS9HDHxv24em98rDK98OP5jHQGPbyIwFyTfmXcG/Pjolikg6p+/hP3BXG3iAL5a5p5ekGuDHDQPC+APxaXNSIsFK7gewC/Zhv4tbpRXDb/CEa2IJeGpoTOcxXAxQO3ClfwvQo+YPonViVJH/uGFnNbSUlQKci1QWj0RwQIH+JdAa5r3TBbRAXfBfWD9Ll6WPoF0tYdQXMKcnWovv4adRL5OKAno4KhlCdA6ZLIFn67bB+O3ml66hXytMEewEYryOUBYoLwwDeJG8QlGw+ggEGUkB8e6MPRezPN79PjZq1XX19BHoxumhS+3nUFrhJcTGfYd60SoPBQ8f67i+JsYJDv+mVfCeNXQoML8mUcd5x0NIUpj7mgUHPcAe4VtO7pFcJuk+qFqwSR5kvx+0T4KKFlBfk2JGlAT3StTCiBal8xs4b6CwIPCEuQKnzcAILjdumgT1Mit5SXl/+wIB9HcfGAflRGvoVXAkQHN42sSdzYLcx+k3WFfWvhg+0zHpLImhbk8yj1h2oIFH7GKwEKSHC8HERRVwaGED46ro8ms5+8GTyB+J/qdaJxQkFnGOT/TyV3sIPHBPBz6G+HUrKuRhnvckK95wntD6Q+v750s69GnkPVVUFnGug2Tv5sG88WQusnVcfY27QLsCC7ugjDBwx0P8X5oHhL0oRPF3Kv73TC584WVmpKeGNKiEgLUE9HzXH7GBamM7sEWDpU9P4bnejVnHsXU3e+sbZXr14nFHTmgcOLGt11yysBMAFy3TjqjEso9nUyawCwCwv3EjVzGB+zO3ppepLft0u7jJuPy3fAd7gDN1sRMPyD7Q6SuAALgwOnqC20rMHqzuHrt1NSB+FvsHe0VYyvKdE9kmJcUFAQO7KgKw1w2qocXI5ikvQsYu8ALqSoYn9fZGODfHML7sWO2PnrqIZ/bNRG+YqaKnxq5rAprxg+T3CBFmogJXiddwmuNYjRxZRriDPYQnFyPiiCK3j8nejds7CxKqHUeprJp6jonoyc5cuHUVTU/yRdNW8k0mgvbw0AkqAIuKAaVTGblsSt2BnuYVeO+XgXtyC0Q3iL2n0A3KSvd4Fe+BO6gHOmpmlHCcmn1xeqwUb7buJK1pYi1FI3jCsJKOJk7E7Hv7ZkSRl2O+Ec/gYA179Mq2WzKeuJE7sWyEsz9/T4NZ3fu4M6eUtC0gflC6SjFcU8nxbwA9sttFaEMlrk6XQG4a4Jtexd4hBcsLXXwzDSLc3e6wgd1TobaLf/ihjNIaFKK5LxtdrxCZD7tC6HBwrpfosBMkRSzJW0a7akWwSXSYQyoAAVB1JuIRfxIvndrRfYl1nvcxTCVYrDuePYPXvnkjX42X2OwL9cYTdlfJRA3RVDq9lIOp0bcLCKlOLjbcG7Pfs0f3Bc9+7dfyIk+h2HppUX0rGzpUQgveUuLL/YippUBgjktGCUzabmydcPr2EPTq233AVy7J+QmUZfXbgMKEerudo+0bSDbuH6kJQIFzM/O6vBsjK4kGECJWsASgHo4NtL2tjt9jHt8AFdMdaRqR9Nfv6nQoIdNHr00I5VpYoxtMAP0v24O9OtgmsZXFPsTrwOweEI+zgiYXDDFi5ZWkKnbC4ksAbAtripis0hpZlCtDSuYBtIShQqs3e2zxE4Hvkwjkf0zimdLVQDsYYEXxXrajF95nFCRSn1w1lMuYWnVDWy0xVCukK4SgHBSc6uda1FsdJ6+pz3yGpbwk4VuH1Pb2SrokTu1bTgOK24vFBIJvPjiEBxKEC3mk4hUuUuSqS8RruwhRdSe4px8Nn6523ixthONPYGXNDsVyKD6Q6FU4QIcotd/BkuuaZdOULVzYsp5r6f8uobSKjv0fwcvfTbEmyqkhi76aTTNrqE+U3a4U+peuQ2RTMW+pWKJrk47C8Q5j3fRuxI5B78/pCsU4USuY8q0K/UVGEUbteiNPUEaoA5HALWpIhZUmL0AUNXWBg4piut0v8D1HLTMIZOOhsAAAAASUVORK5CYII=" type="image/png">
  <style>
    html, body {
      height: 100%;
      margin: 0;
      font-family: Arial, sans-serif;
      overflow-x: hidden; /* Disable horizontal scrolling */
    }

    /* Full page container */
    body {
      display: flex;
      flex-direction: column;
      justify-content: flex-start; /* Keep header at the top */
      align-items: center;
      background: linear-gradient(to right,rgb(119, 117, 117),rgb(77, 74, 71));
    }

    /* Header style */
    header {
      width: 100%;
      background-color: #333;
      color: white;
      padding: 20px;
      text-align: center;
      font-size: 24px;
      box-sizing: border-box; /* Ensure padding doesn't cause overflow */
    }

    /* Main content area to center the button */
    .main-content {
      display: flex;
      flex: 1; /* Take up remaining space */
      justify-content: center; /* Center horizontally */
      align-items: center; /* Center vertically */
      width: 100%;
    }

    /* Button style */
    .button-link {
      display: flex;
      width: 100px;
      height: 50px;
      font-size: 16px;
      font-weight: bold;
      color: white;
      text-decoration: none;
      text-align: center;
      justify-content: center;
      align-items: center;
      background: rgb(11, 174, 11);
      border-radius: 5px;
      box-shadow: 0 4px 6px rgb(38, 41, 37);
      transition: background 0.3s;
    }

    .button-link:hover {
      background: rgb(51, 231, 19);
    }
  </style>
</head>
<body>

  <header>
    WiFi Lamp Control
  </header>

  <div class="main-content">
    <a href="/LIGHTON" class="button-link">ON</a>
  </div>

</body>
</html>
)rawliteral";

const char* onPage = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>WiFi Lamp</title>
  <link rel="icon" href="data:image/png;base64,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" type="image/png">
  <style>
    html, body {
      height: 100%;
      margin: 0;
      font-family: Arial, sans-serif;
      overflow-x: hidden; /* Disable horizontal scrolling */
    }

    /* Full page container */
    body {
      display: flex;
      flex-direction: column;
      justify-content: flex-start; /* Keep header at the top */
      align-items: center;
      background: linear-gradient(to right, #ff7e5f, #feb47b);
    }

    /* Header style */
    header {
      width: 100%;
      background-color: #333;
      color: white;
      padding: 20px;
      text-align: center;
      font-size: 24px;
      box-sizing: border-box; /* Ensure padding doesn't cause overflow */
    }

    /* Main content area to center the button */
    .main-content {
      display: flex;
      flex: 1; /* Take up remaining space */
      justify-content: center; /* Center horizontally */
      align-items: center; /* Center vertically */
      width: 100%;
    }

    /* Button style */
    .button-link {
      display: flex;
      width: 100px;
      height: 50px;
      font-size: 16px;
      font-weight: bold;
      color: white;
      text-decoration: none;
      text-align: center;
      justify-content: center;
      align-items: center;
      background: rgb(169, 9, 9);
      border-radius: 5px;
      box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
      transition: background 0.3s;
    }

    .button-link:hover {
      background: rgb(244, 19, 53);
    }
  </style>
</head>
<body>

  <header>
    WiFi Lamp Control
  </header>

  <div class="main-content">
    <a href="/LIGHTOFF" class="button-link">OFF</a>
  </div>

</body>
</html>
)rawliteral";
