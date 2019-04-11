const puppeteer = require('puppeteer');

(async () => {
  const browser = await puppeteer.launch();
  const page = await browser.newPage();
  const url = 'https://marketingplatform.google.com/about/partners/find-a-partner?utm_source=marketingplatform.google.com&utm_medium=et&utm_campaign=marketingplatform.google.com%2Fabout%2Fpartners%2F'
  await page.goto(url);

  const titles = await page.evaluate(()=>
    Array.from(document.querySelectorAll('div.compact h3.title')).map(val=>val.innerText.trim()));
    console.log(titles);

  const logos = await page.evaluate(()=>
    Array.from(document.querySelectorAll('div.compact div.logo img')).map((logo)=>logo.src));
    console.log(logos);
  

  
  await browser.close();
})();