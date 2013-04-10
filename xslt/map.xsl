<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
    <h2>Points:</h2>
    <xsl:apply-templates select="/osm/way" />
  </body>
  </html>
</xsl:template>



<xsl:template match="way">
    <!-- Select only building's ways -->
    <xsl:if test="child::tag[@k='building'] and child::tag[@v='yes']">
        <!-- Some work with 'way' -->
        tag 'way' [<xsl:value-of select="attribute::id"/>] <br />
        noderefs: <br />
        <xsl:for-each select="child::nd">
            <xsl:value-of select="@ref"/> <br />

            <!-- Get lat and lon of for nd's ref node -->

            <xsl:variable name="ndref" select="@ref" />
            <xsl:apply-templates select="//node[@id=$ndref]"/>


<!--             <xsl:call-template name="show_points">
                <xsl:with-param name="testparam" select="@ref"/>
            </xsl:call-template> -->

        <br />
        </xsl:for-each>
        <br />
    </xsl:if>
</xsl:template>






<xsl:template name="show_points" match="node">
<xsl:param name="testparam" />
     <xsl:if test="$testparam"> <!-- If we pass any argument -->
        <!-- Reference in param: <xsl:value-of select="$testparam" /> -->
        <xsl:if test="$testparam = @id">
            lat: <xsl:value-of select="attribute::lat" /> <br />
            lon: <xsl:value-of select="attribute::lat" /> <br />
        </xsl:if>
     </xsl:if>
</xsl:template>


<xsl:template match="node">
        lat: <xsl:value-of select="attribute::lat" /> <br />
        lon: <xsl:value-of select="attribute::lat" /> <br />
</xsl:template>

</xsl:stylesheet>