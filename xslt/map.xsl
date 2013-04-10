<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
    <h2>Points:</h2>
    <xsl:apply-templates/>
  </body>
  </html>
</xsl:template>

<xsl:template match="way">
    <xsl:apply-templates/>

    <xsl:if test="child::tag[@k='building'] and child::tag[@v='yes']">   <!-- if exist way/tag[@k="building"]-->
        <p>
        <!-- Some work with 'way' -->
        tag 'way' [<xsl:value-of select="attribute::id"/>] <br />
        noderefs: <br />
        <xsl:for-each select="child::nd">
            <xsl:value-of select="@ref"/> <br />
        </xsl:for-each>

        </p>
    </xsl:if>

</xsl:template>

<!--
    <xsl:for-each select="preceding-sibling::nd[@ref]">
      Point: <xsl:value-of select="."/>

    </xsl:for-each> -->
</xsl:stylesheet>